#ifndef SDS_H
#define SDS_H

typedef struct sdshdr
{
    int len;
    int free;
    char* buf;
}*sds;

sds sdsnew(char *);//创建一个sds，其中写入指定字符串

sds sdsempty(void);//创建一个空的sds

sds sdsnewlen(sds, int);//为sds分配指定空间

void sdsfree(sds);//删除一个sds并释放空间

sds sdsdup(sds);//复制一个sds

sds  sdsclear(sds);//清空sds保存的字符串


#endif
