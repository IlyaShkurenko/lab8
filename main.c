#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <locale.h>
#include <parsepath.h>
#include <jsonparser.h>
#include <fileparser.h>
#include <choosefunction.h>
#include "workwithstrings.h"
#include "result.h"
#include "net.h"
#include <choosefunction.h>
#include <fav.h>


#define BUFFER_LEN 10240

int main(int argc, char * argv[]) {
    setlocale(LC_ALL,"ru_RU.utf8");
    char * content = (char*)malloc(BUF_SIZE*1000* sizeof(char));
    List *list = List_new();
    Result *res = Result_new("","");
    List_add(list, enterCompose("ilya,fpm,10,1,34.5"));
    List_add(list, enterCompose("dima,fpm,23,2,10.5"));
    srand(time(0));
    const int port = 9999;

    TcpListener * server = TcpListener_init(&(TcpListener){});
    IpAddress * address = IpAddress_initAny(&(IpAddress){}, port);
    if(!TcpListener_bind(server, address)) {
        perror("tcp bind");
        return 1;
    }
    if (!TcpListener_start(server)) {
        perror("tcp server start");
        return 1;
    }
    printf("TCP Server is listening on port %d\n",
           IpAddress_port(TcpListener_address(server)));

    NetMessage * message = NetMessage_init(
            &(NetMessage){},  // value on stack
            (char[BUFFER_LEN]){},  // array on stack
            BUFFER_LEN);
    //
    // to store information about current client
    TcpClient client;
    while (1) {
        puts(">> Waiting for connection...");
        //
        // wait for someone to connect to server
        TcpListener_accept(server, &client);
        // wait for data from client
        if(!TcpClient_receive(&client, message)) {
            perror("recv");
            return 1;
        }
        IpAddress * clientAddress = TcpClient_address(&client);
       // NetMessage_setDataString(message,str);
        char* strToCopy = (char*)malloc(BUF_SIZE* sizeof(char));
        strcpy(strToCopy,NetMessage_data(message));
        char * ch = strchr(strToCopy,'H');
        clearString(strToCopy,(ch-strToCopy));
        clearStringFromBegin(strToCopy,4);
        printf(">> Received message from %s:%d (%d bytes): `%s`\n",
               IpAddress_address(clientAddress),  // client IP-address
               IpAddress_port(clientAddress),  // client port
               NetMessage_dataLength(message),
               NetMessage_data(message));
        char* json = (char*)malloc(10000* sizeof(char));
        choose(list,res,strToCopy,content,json);
        NetMessage_setDataString(message, json);
        free(json);
        if(!TcpClient_send(&client, message)) {
            perror("send");
            return 1;
        }
        printf(">> String sent to client:\r\n%s\r\n", NetMessage_data(message));
        // close tcp connection
        TcpClient_close(&client);
    }
    // close listener
    TcpListener_close(server);
    return 0;
}