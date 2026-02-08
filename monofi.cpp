#include "util/menu_design.h"
#include "util/backend.h"
using namespace std;

int main(){
    int input;
    while (true) {
        backend.get_interface();
        menu.menu_show();
        
        cout << "-> ";
        cin >> input;
        
        switch (input)
        {
        case 1:
            backend.start_interface_1();
            break;
        case 2:
            backend.stop_interface_2();
            break;
        case 3:
            backend.show_disturbing_proc_3();
            break;
        case 4:
            backend.kill_disturbing_proc_4();
            break;
        case 5:
            backend.start_interface_channel_5();
            break;
        case 6:
            bs.clear();
            menu.interface_menu();
            backend.select_interface_6();
            break;
        case 7:
            backend.show_networks_7();
            break;
        case 8:
            backend.targeted_monitoring_8();
            break;
        case 9:
            backend.endless_deauth_9();
            break;
        case 10:
            backend.deauth_attack_10();
            break;
        case 11:
            backend.targe_against_clinet_11();
            break;
        case 12:
            backend.crack_wpa_12();
            break;
        case 13:
            backend.fake_access_point_13();
            break;
        case 14:
            backend.visualize_network_14();
            break;
        case 15:
            backend.displays_wpa_capable_15();
            break;
        case 16:
            backend.reset_output_folder_16();
            break;
        case 17:
            break;
        case 18:
            break;
        default:
            break;
        }
    }
    return 0;
    
}
