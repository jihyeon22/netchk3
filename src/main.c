#include <stdio.h>
#include <stdlib.h>
#include <signal.h> 

#include <at/at_util.h>
#include <logd_rpc.h>

void sigint_handler( int signo)
{
	printf("signo = [%d]\n", signo);
	if(signo == 2) //ctrl+c
	   exit(0);
}

void noti_proc(const char* buffer, int len)
{
	printf("test app noti proc +++++++++++++++++++++++++++\r\n");
	printf("%s : [%s](%d)\r\n", __func__, buffer, len);
	printf("test app noti proc ---------------------------\r\n");	
}

void sms_proc(const char* phone_num, const char* recv_time, const char* msg)
{
	printf("test app sms proc +++++++++++++++++++++++++++\r\n");
	printf("%s :  phone_num [%s]\r\n", __func__,  phone_num);	
	printf("%s : recv_time [%s]\r\n", __func__,  recv_time);	
	printf("%s : msg [%s]\r\n", __func__,  msg);	
	printf("test app sms proc ---------------------------\r\n");
	//_parse_sms(buffer);
}

int main(int argc, char* argv[])
{
	int ret;
	printf("netchk2 is empty program... bye bye\r\n");

	signal( SIGINT, sigint_handler);
	logd_init();

	if(argc < 2) {
		printf("usage...\n");
		printf("-s : server create\n");
		printf("-c : client create\n");
		return 0;


	}
	printf("argc = [%d]\n", argc);
	
	if(!strcmp(argv[1], "-s")) {
		printf("at_listener_open call()\n");
		at_listener_open();
	}
	//else {
		printf("at_open call()\n");
		ret = at_open(e_DEV_TX500, noti_proc, sms_proc, "console");
		//ret = at_open(e_DEV_TX500, NULL, NULL, "console");
		printf("at_open ret[%d]\n", ret);
	//}

	while(1) {
		LOGD(eSVC_COMMON, "netchk2 alive app #2\n");
		LOGE(eSVC_COMMON, "netchk2 alive app #2\n");
		LOGT(eSVC_COMMON, "netchk2 alive app #2\n");
		printf("netchk2 alive app #2\n");
		sleep(1);		
	}

	return 0;
}

