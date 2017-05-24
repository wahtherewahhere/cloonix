/*****************************************************************************/
/*    Copyright (C) 2006-2017 cloonix@cloonix.net License AGPL-3             */
/*                                                                           */
/*  This program is free software: you can redistribute it and/or modify     */
/*  it under the terms of the GNU Affero General Public License as           */
/*  published by the Free Software Foundation, either version 3 of the       */
/*  License, or (at your option) any later version.                          */
/*                                                                           */
/*  This program is distributed in the hope that it will be useful,          */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            */
/*  GNU Affero General Public License for more details.a                     */
/*                                                                           */
/*  You should have received a copy of the GNU Affero General Public License */
/*  along with this program.  If not, see <http://www.gnu.org/licenses/>.    */
/*                                                                           */
/*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/*---------------------------------------------------------------------------*/
#include "io_clownix.h"
#include "rpc_clownix.h"
#include "doorways_sock.h"
#include "client_clownix.h"
#include "cloonix_conf_info.h"


/*****************************************************************************/
void help_sav_derived(char *line)
{
  printf( "\n\n\n%s <name> <saving_file>\n", line);
  printf( "\nThe saving_file must not exist.");
  printf( "\nNeeds the backing associated qcow2 to run.\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_sav_full(char *line)
{
  printf( "\n\n\n%s <name> <saving_file>\n", line);
  printf( "\nThe saving_file must not exist.");
  printf( "\nCan run solo, is autonomous.\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_sav_topo(char *line)
{
  printf( "\n\n\n%s <saving_dir>\n", line);
  printf( "\nThe saving_dir must not exist.");
  printf( "\nFor each machine on the canvas, a derived file is saved.");
  printf( "\nA replay script file named after the server is created.\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_sav_topo_full(char *line)
{
  printf( "\n\n\n%s <saving_dir>\n", line);
  printf( "\nThe saving_dir must not exist.");
  printf( "\nFor each machine on the canvas, a full file is saved.");
  printf( "\nA replay script file named after the server is created.\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_creboot_vm(char *line)
{
  printf("\n\n\n%s <name>\n", line);
  printf("\nRequest a reboot to the cloonix agent\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_qreboot_vm(char *line)
{
  printf("\n\n\n%s <name>\n", line);
  printf("\nRequest a reboot to qemu kvm\n\n\n");
}
/*---------------------------------------------------------------------------*/


/*****************************************************************************/
void help_halt_vm(char *line)
{
  printf("\n\n\n%s <name>\n", line);
  printf("\nFor kvm machines, request a poweroff to the cloonix agent\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_del_vm(char *line)
{
  printf("\n\n\n%s <name>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/


/*****************************************************************************/
void help_add_sat(char *line)
{
  printf("\n\n\n%s <name>\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_add_raw(char *line)
{
  printf("\n\n\n%s <name>\n\n", line);
  printf("\n%s eth0\n\n", line);
  printf("  Specifique to have a raw socket to an interface\n");
  printf("  real hardware host interface, the name of the\n");
  printf("  real interface must be given. \n");
  printf("  This interface is made promiscuous.\n");
  printf("  The interface is left in promiscuous mode after use.\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_add_wif(char *line)
{
  printf("\n\n\n%s <name>\n\n", line);
  printf("\n%s wlan0\n\n", line);
  printf("  Specifique to have a raw socket to a wlan\n");
  printf("  real hardware host interface, the name of the\n");
  printf("  real interface must be given. \n");
  printf("  Swaps mac address to show the real wlan mac to the outside\n");
  printf("  Do not use wif, hack for personal use.\n\n\n");
}
/*---------------------------------------------------------------------------*/


/*****************************************************************************/
void help_del_sat(char *line)
{
  printf("\n\n\n%s <sat>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_add_c2c(char *line)
{
  printf("\n\n\n%s <name> <distant_name>",line);
  printf("\n\tDistant cloonix server name:");
  printf("\n%s\n", cloonix_conf_info_get_names());
  printf("\n\nexemple:\n");
  printf("\t%s to_mito mito\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_add_vl2sat(char *line)
{
  printf("\n\n\n%s <name> <num> <lan>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_del_vl2sat(char *line)
{
  printf("\n\n\n%s <name> <num> <lan>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_snf_on(char *line)
{
  printf("\n\n\n%s <name>\n\n\n", line);
}
void help_snf_off(char *line)
{
  printf("\n\n\n%s <name>\n\n\n", line);
}
void help_snf_get_file(char *line)
{
  printf("\n\n\n%s <name>\n\n\n", line);
}
void help_snf_set_file(char *line)
{
  printf("\n\n\n%s <name> <pcap file path>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_mud_lan(char *line)
{
  printf("\n\n\n%s <name> \"txt of msg\"\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_mud_sat(char *line)
{
  printf("\n\n\n%s <name> \"txt of msg\"\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_mud_eth(char *line)
{
  printf("\n\n\n%s <name> <num> \"txt of msg\"\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_sub_sysinfo(char *line)
{
  printf("\n\n\n%s <name>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/


/*****************************************************************************/
void help_sub_endp(char *line)
{
  printf("\n\n\n%s <name> <num>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_sav(char *line)
{
  printf("\n\n\n%s <directory path>\n\n\n", line);
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_event_hop(char *line)
{
  printf("\n\n%s doors\n", line);
  printf("\n     or\n");
  printf("\n%s eth <name> <num>\n", line);
  printf("\n     or\n");
  printf("\n%s <hop_type> <name>\n", line);
  printf("for hop_type = lan, sat\n\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_a2b_config(char *line)
{
  printf("\n\n%s <name> <cmd> <dir> <val>\n", line);
  printf("\nname is the a2b name.");
  printf("\ncmd =  \"loss\" \"delay\" \"qsize\" \"bsize\" \"rate\"");
  printf("\ndir =  \"A2B\" \"B2A\"");
  printf("\nval is an integer.\n");
  printf("\n\n");
}
/*---------------------------------------------------------------------------*/

/*****************************************************************************/
void help_a2b_dump(char *line)
{
  printf("\n\n%s <name>\n", line);
  printf("\nname is the a2b name.");
  printf("\n\n");
}
/*---------------------------------------------------------------------------*/


