#include <sys/time.h>
#include <stdlib.h>
#include <err.h>
#include <event.h>
#include <evhttp.h>
#include <string.h>
#include <fav.h>
#include <result.h>
#include <choosefunction.h>

#define STRING_SIZE 1000

char *getAnswer(const char *uri, char *answer,Result* res, List* list, char * content);

void handler(struct evhttp_request *req, void *arg) {
    struct evbuffer *buf;
    char * content = (char*)malloc(BUF_SIZE*1000* sizeof(char));
    List *list = List_new();
    Result *res = Result_new("","");
    List_add(list, enterCompose("ilya,fpm,10,1,34.5"));
    List_add(list, enterCompose("dima,fpm,23,2,10.5"));
    buf = evbuffer_new();
    if (buf == NULL) err(1, "failed to create response buffer");
    char answer[STRING_SIZE] = "";
    getAnswer(evhttp_request_uri(req), answer, res, list, content);
    printf("Request to server: GET %s\n",evhttp_request_uri(req));
    if (evhttp_request_get_command(req) != EVHTTP_REQ_GET) {
        evhttp_send_reply(req, HTTP_BADMETHOD, "BAD METHOD", buf);
    } else if (answer == NULL) {
        evhttp_send_reply(req, HTTP_NOTFOUND, "NOT FOUND", buf);
    } else {
        evbuffer_add_printf(buf, "%s\n", answer);
        evhttp_send_reply(req, HTTP_OK, "OK", buf);
        printf("Response to client:\n%s\n",answer);
    }
}

int main(int argc, char **argv) {
    struct evhttp *httpd;
    event_init();
    const int port = 9000;
    const char * host = "127.0.0.1";
    httpd = evhttp_start(host, port);
    evhttp_set_gencb(httpd, handler, NULL);
    printf("Server started on host %s:%i\n",host,port);
    event_dispatch();
    evhttp_free(httpd);
    return 0;
}

char *getAnswer(const char *uri, char *answer,Result* res, List* list, char * content) {
    char* json = (char*)malloc(10000* sizeof(char));
    char *str = (char*)malloc(10000* sizeof(char));
    strcpy(str,uri);
    choose(list,res,str,content,answer);
    return answer;
}