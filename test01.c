#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "json-c/json.h"

void getFirstKey(const char *sname, char *first_sname)
{
	char *ptr;

	ptr = strchr(sname, '.');
	if( ptr != NULL )
	{
		strcpy(first_sname, sname);
		ptr = strchr(first_sname, '.');
		*ptr = '\0';
	}
}

void getSubKey(const char *sname, char *sub_sname)
{
	char *ptr;

	ptr = strchr(sname, '.');
	if( ptr != NULL )
	{
		strcpy(sub_sname, ptr+1);
	}
}

void getValByKey(json_object* jobj, const char *sname)
{
	char first_sname[128];
	char sub_sname[128];
    json_object *pval =NULL;
    enum json_type type;

	memset(first_sname, 0, 128);
	memset(sub_sname, 0, 128);

	getFirstKey(sname, first_sname);
	if( strlen(first_sname) <= 0 )
	{
		strcpy(first_sname, sname);
	}

	pval = json_object_object_get(jobj, first_sname);

	if(NULL != pval){
	    type = json_object_get_type(pval);
	    switch(type)
	    {
			case json_type_boolean:
				printf("key:%s, value:%d\n",sname,json_object_get_boolean(pval));
				break;
			case json_type_double:
				printf("key:%s, value:%f\n",sname,json_object_get_double(pval));
				break;
			case json_type_int:
				printf("key:%s, value:%d\n",sname,json_object_get_int(pval));
				break;
			case json_type_object:
				getSubKey(sname, sub_sname);
				if( strlen(sub_sname) > 0 )
				{
					getValByKey(pval,sub_sname);
				}
				break;
			case json_type_array:
				break;
			case json_type_string:
				printf("key:%s, value:%s\n",sname,json_object_get_string(pval));
				break;
	        default:
	            printf("default: key:%s\n",first_sname);
	            break;
	    }
	} else {
		printf("%s not found\n", first_sname);
	}
}


int main(int argc, char *argv[])
{
    json_object *pobj = NULL;
    //pobj = json_object_from_file("test01.json");

    char * string = "{\
        \"version\":\"1.0\",\
        \"params\":\
            {\
	        \"light_switch\":1,\
		    \"light_intensity\":21,\
		    \"led_r\":0,\
		    \"led_g\":0,\
		    \"led_b\":0,\
		    \"uv\":114,\
		    \"temp\":28.25,\
		    \"hum\":0\
		}\
        }";
	
    pobj = json_tokener_parse(string); 
    //getValByKey(pobj,"params.light_switch");
    //getValByKey(pobj,"version");

    getValByKey(pobj, argv[1]);
    return 0;
}

