#include<stdio.h>
#include"../mxml/mxml.h"

int main(void)
{
    FILE *fp = fopen("QQ.xml","r");
    //加载文件
    mxml_node_t *xml = mxmlLoadFile(NULL,fp,MXML_NO_CALLBACK);
    //创建三个空节点
    mxml_node_t *pic = NULL;
    mxml_node_t *resurl = NULL;
    mxml_node_t *thumbnail = NULL;
    //查找Pic元素
    pic = mxmlFindElement(xml,xml,"Pic",NULL,NULL,MXML_DESCEND); 
    
    while(pic)
    {
        resurl = mxmlFindElement(pic,xml,"resurl","md5",NULL,MXML_DESCEND);
        if(resurl == NULL)
        {
            printf("resurl == NULL");
        }
        else
        {
            printf("md5 == %s\n",mxmlElementGetAttr(resurl,"md5"));
            printf("text:%s\n",mxmlGetText(resurl,NULL));
        }
        thumbnail = mxmlFindElement(pic,xml,"thumbnail","md5",NULL,MXML_DESCEND);
        if(resurl == NULL)
        {
            printf("thumbnail == NULL");
        }
        else
        {
            printf("md5 == %s\n",mxmlElementGetAttr(thumbnail,"md5"));
                        printf("text:%s\n",mxmlGetText(thumbnail,NULL));
        }
        pic = mxmlFindElement(pic,xml,"Pic",NULL,NULL,MXML_DESCEND);
    }
    mxmlDelete(xml);
    fclose(fp);
    return 0;
}
