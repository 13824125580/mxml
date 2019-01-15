#include"../mxml/mxml.h"

int main()
{
    //创建一个xml文件
    mxml_node_t *xml = mxmlNewXML("1.0");
    //新增一个节点html
    mxml_node_t *html = mxmlNewElement(xml,"html");
    //在html节点下新增一个head节点
    mxml_node_t *head = mxmlNewElement(html,"head");
    //在head节点下新增一个title节点
    mxml_node_t *title = mxmlNewElement(head,"title");
    //title节点添加内容"Docment"
    mxmlNewText(title,0,"Docment");
    
    //在html节点下新增body节点
    mxml_node_t *body = mxmlNewElement(html,"body");
    //在body节点下新增p节点
    mxml_node_t *p = mxmlNewElement(body,"p");
    //给p节点增加属性style，属性内容为 color:red
    mxmlElementSetAttr(p,"style","color:red");
    //给p节点增加内容 Helloworld.cpp
    mxmlNewText(p,0,"Helloworld.cpp");
    
    //打开文件index.xml
    FILE *fp = fopen("index.xml","wb");
    //保存节点到xml文件
    mxmlSaveFile(xml,fp,MXML_NO_CALLBACK);
    fclose(fp);
    //删除节点内存
    mxmlDelete(xml);
    return 0;
}
