#include <stdio.h>
#include "../mxml/mxml.h"

int main(void)
{
    FILE *fp = fopen("weather.xml","rb");
    mxml_node_t *xml = mxmlLoadFile(NULL,fp,MXML_NO_CALLBACK);
    mxml_node_t *city = NULL;
    city = mxmlFindElement(xml,xml,"city",NULL,NULL,MXML_DESCEND);
    while(city)
    {
        printf("省市名称:%s \n",mxmlElementGetAttr(city,"quName"));
        printf("省会名称:%s \n",mxmlElementGetAttr(city,"cityname"));
        
        printf("最低气温:%s \n",mxmlElementGetAttr(city,"tem1"));
        printf("最高气温:%s \n",mxmlElementGetAttr(city,"tem2"));
        
        printf("天气情况:%s \n",mxmlElementGetAttr(city,"stateDetailed"));
        printf("风力:%s \n\n",mxmlElementGetAttr(city,"windState"));
        city = mxmlFindElement(city,xml,"city",NULL,NULL,MXML_DESCEND);
    }
    
    return 0;
}
