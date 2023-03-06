#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sds.h"

//创建一个sds，其中写入指定字符串
sds sdsnew(char *s) {
    sds ns = (sds)malloc(sizeof(struct sdshdr));
    ns -> len = strlen(s);
    ns -> free = 0;
    ns -> buf = (char *)malloc(sizeof(char)*(ns->len + 1));

    int i = 0;
    for(; i < ns->len; i++ ) {
        (ns->buf)[i] = s[i];
    }
    (ns->buf)[i] = '\0';
    return ns;
}

//为sds分配指定空间
sds sdsnewlen(sds ns, int len) {
    //todo:小于符合要求的空间
    ns -> free = len - ns->len - 1;
    char *str = (char *)malloc(sizeof(char) * (ns->len + 1));

    int i = 0;
    for(; i < (ns->len); i++ ) {
        str[i] = (ns->buf)[i];
    }
    str[i] = '\0';

    ns->buf = (char *)malloc(sizeof(char) * len);
    for(i = 0; i < (ns->len); i++ ) {
        str[i] = (ns->buf)[i];
    }
    str[i] = '\0';
    free(str);
    return ns;
}

//创建一个空的sds
sds sdsempty(void){
    sds ns = (sds)malloc(sizeof(struct sdshdr));
    ns -> len = 0;
    ns -> free = 0;
    ns -> buf = (char*)malloc(sizeof(char));
    (ns->buf)[0] = '\0';
    return ns;
}

//删除一个sds并释放空间
void sdsfree(sds *ns){
    (*ns) -> free = 0;
    (*ns) -> len = 0;
    free((*ns)->buf);
    free(*ns);
}

//复制一个sds
sds sdsdup(sds os){
    sds ns = (sds)malloc(sizeof(struct sdshdr));
    ns -> free = os -> free;
    ns -> len = os -> len;
    ns -> buf = (char*)malloc(sizeof(char)*(ns->free + ns->len + 1));

    int i = 0;
    for(; i<os->len; i++){
        ns->buf[i]=os->buf[i];
    }

    ns->buf[i]='\0';
    return ns;
}

//清空sds保存的字符串
sds sdsclear(sds ns){
    int total=ns->len + ns->free + 1;
    ns -> len = 0;
    ns -> free = total - 1;
    ns -> buf[0] = '\0';
    return ns;
}
