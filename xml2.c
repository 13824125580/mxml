#include<stdio.h>
#include"../mxml/mxml.h"

int main(void)
{
    FILE *fp = fopen("new.xml","w");
    
    //生成xml文件的头 <?xml version="1.0" encoding="utf-8"?>
    mxml_node_t *xml = mxmlNewXML("1.0");
    //添加一个新节点note
    mxml_node_t *note = mxmlNewElement(xml,"note");
    //往note节点添加子节点to
    mxml_node_t *to = mxmlNewElement(note,"to");
    //给to节点添加文本内容
    mxmlNewText(to,0,"科比");
    //给to节点设置属性 time 属性内容为 1115
    mxmlElementSetAttr(to,"time","1115");
    
    //给note节点添加子节点from
    mxml_node_t *from = mxmlNewElement(note,"from");
    //给from节点添加文本内容
    mxmlNewText(from,0,"瓦妮莎");
    //给note节点添加子节点heading
    mxml_node_t *heading = mxmlNewElement(note,"heading");
    //给heading节点添加文本内容
    mxmlNewText(heading,0,"Reminder");
    
    //给note节点添加子节点body
    mxml_node_t *body = mxmlNewElement(note,"body");
    //给body节点添加文本内容
    mxmlNewText(body,0,"Don't froget NBA programe this weekend!");
    //保存节点内容
    mxmlSaveFile(xml,fp,MXML_NO_CALLBACK);
    
    fclose(fp);
    return 0;
}
