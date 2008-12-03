//////////////////////////////////////////////////////////
// This file is a part of Nanos Copyright (C) 2008, 2009//
// ashok.s.das@gmail.com                                //
//////////////////////////////////////////////////////////
// basic shell                                          //
//                                                      //
//////////////////////////////////////////////////////////

#include "shell.h"
#include "cmos.h"
#include "gcpu.h"
#include "multiboot.h"
shell::shell()
{
	cout.clear();	
	cout.SetTextColour(BRIGHTBLUE);
	for(int i=0;i<6;i++)	
	cout<<logo[i]<<"\n";
	cout.SetTextColour(WHITE);
}
void shell::about()
{
	cout.SetColour(BLUE,BLACK,1);
	cout<<"NanOS";
	cout.SetColour(WHITE,BLACK,0);
	cout<<" an hobby and experimental OS kernel Written in C++(g++) and NASM\n";
	cout<<"Authour: Ashok Shankar Das (ashok.s.das@gmail.com)\n";
}
void shell::start()
{
	cout<<"Starting shell\n";
	
	while(1)
	{
		unsigned char *cmd;		
		cout<<"NanOS-#>";
		cin>>cmd;
		cout<<" \nCommand : "<<cmd<<"\n";
		if(String::strncmp((const char*)cmd,"about",5)==0)
			about();
		else if(String::strncmp((const char*)cmd,"help",4)==0)
			help();
		else if(String::strncmp((const char*)cmd,"clear",5)==0)
			cout.clear();
		else if(String::strncmp((const char*)cmd,"date",4)==0)
			get_cmos_date_time();
		else if(String::strncmp((const char*)cmd,"hello",5)==0)
			cout<<"Hi, how do you do???";
		else if(String::strncmp((const char*)cmd,"cpuinfo",7)==0)
			cpuinfo();
		else if(String::strncmp((const char*)cmd,"meminfo",7)==0)
			meminfo();
		else
			cout<<"Unknown Command\n";
	}
}
char *shell::logo[6]={
"'|.   '|'                   ..|''||    .|'''.|  ",
" |'|   |   ....   .. ...   .|'    ||   ||..  '  ",
" | '|. |  '' .||   ||  ||  ||      ||   ''|||.  ",
" |   |||  .|' ||   ||  ||  '|.     || .     '|| ",
".|.   '|  '|..'|' .||. ||.  ''|...|'  |'....|'  ",
"================================================\n"};
void shell::meminfo()
{
	extern unsigned int memupper;	
	cout.flags(hex|showbase);
	cout<<"Kernel starts at "<<(unsigned int)get_kernel_start()<<"\n";
	cout<<"Kernel Ends at   "<<(unsigned int)get_kernel_end()<<"\n";
	cout.flags(dec);
	cout<<"Total Memory     "<<(memupper/1024)+1<<"\n";
}
void shell::help()
{
	cout<<"\n\tAvailable Commands ...\n\n";
	cout<<"\tabout -> about the NanOS\n";
	cout<<"\tclear -> clears the screen\n";
	cout<<"\tdate  -> displays current date and time\n";
	cout<<"\thelp  -> displays this help screen\n";
	cout<<"\thello -> displays hi string\n";
	cout<<"\tcpuinfo -> displays cpu info\n";
	cout<<"\tmeminfo -> displays memory info\n";
}
