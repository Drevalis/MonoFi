#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <ctime>
#include <vector>
using namespace std;


void run_cmd(const vector<string>& args) {
    pid_t pid = fork();

    if (pid == 0) {
        vector<char*> c_args;
        for (const auto& s : args)
            c_args.push_back(const_cast<char*>(s.c_str()));
        c_args.push_back(nullptr);

        execvp(c_args[0], c_args.data());
        perror("execvp failed");
        _exit(1);
    } 
    else {
        wait(nullptr);
    }
}


class shortcuts_settings_backend{
    public:

        void clear() {
            system("clear");
        };
        void space() {
            cout << endl;
        };
        
        void airmon_ng() {
            run_cmd({
                "sudo",
                "airmon-ng",
                });
        };
        
 };
shortcuts_settings_backend bs;

class input_vars {
    public:
        
        string interface;
        string enter_var;
        string interface_start;
        string interface_stop;
        string interface_start_channel;
        string channel_airmon;
        string commands;
        string monitoring_mac;
        string monitoring_channel;
        string monitoring_output_name;
        string outputpath = "output/";
        string wordliestpath = "psw/";
        string endlessdeauth_mac;
        string deauthattack_packages;
        string deauthattack_mac;
        string deauthspecific_mac;
        string deauthspecific_client;
        string aircrack_output;
        string aircrack_list;
        string airbase_name;
        string airbase_channel;
        string airgraph_csv;
        string airgraph_outputname;
};

class backend_settings:public input_vars {
    public:
        string interface = "wlan1";
        int start_interface_1() {
            bs.clear();
            system("sudo airmon-ng");
            cout << "Enter interface: ";
            cin >> interface_start;
            run_cmd({
                "sudo",
                "airmon-ng",
                "start",
                interface_start});
            sleep(1);
            return 0;
        }

        int stop_interface_2() {
            bs.clear();
            bs.airmon_ng();
            cout << "Enter interface: ";
            cin >> interface_stop;
            run_cmd({
                "sudo",
                "airmon-ng",
                "stop",
                interface_stop,
            });
            sleep(1);
            return 0;
        }

        int  show_disturbing_proc_3() {
            bs.clear();
            run_cmd({
                "sudo",
                "airmon-ng",
                "check",
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;
        }

        int kill_disturbing_proc_4() {
            bs.clear();
            run_cmd({
                "sudo",
                "airmon-ng",
                "check",
                "kill",
            });
            sleep(3);
            return 0;
        }

        int start_interface_channel_5() {
            bs.clear();
            bs.airmon_ng();
            cout << "Enter interface: ";
            cin >> interface_start_channel;
            bs.clear();
            cout << "Enter channel: ";
            cin >> channel_airmon;
            run_cmd({
                "sudo",
                "airmon-ng",
                "start",
                interface_start_channel,
                channel_airmon,
            });
            return 0;
        }
        int select_interface_6() {
            cout << "COMING";
            return 0;
        }
        int show_networks_7() {
            bs.clear();
            if (interface.empty()){
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            run_cmd({
                "sudo",
                "airodump-ng",
                interface,
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;
        }

        int targeted_monitoring_8() {
            bs.clear();
            if (interface.empty()){
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            cout << "Enter MAC: ";
            cin >> monitoring_mac;
            bs.space();
            cout << "Enter channel: ";
            cin >> monitoring_channel;
            bs.space();
            cout << "Enter ouput file name: ";
            cin >> monitoring_output_name;
            monitoring_output_name = outputpath + monitoring_output_name;
            run_cmd({
                "sudo",
                "airodump-ng",
                "-c",
                monitoring_channel,
                "-w",
                monitoring_output_name,
                "--bssid",
                monitoring_mac,
                interface
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;
        }

        int endless_deauth_9() {
            bs.clear();
            if (interface.empty()){
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            cout << "Enter MAC: ";
            cin >> endlessdeauth_mac;
            run_cmd({
                "sudo",
                "aireplay-ng",
                "--deauth",
                "0",
                "-a",
                endlessdeauth_mac,
                interface,
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;

        }

        int deauth_attack_10() {
            bs.clear();
            if (interface.empty()){
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            cout << "Enter how many packages: ";
            cin >> deauthattack_packages;
            cout << "Enter MAC: ";
            cin >> deauthattack_mac;
            run_cmd({
                "sudo",
                "aireplay-ng",
                "--deauth",
                deauthattack_packages,
                "-a",
                deauthattack_mac,
                interface,
            });
            return 0;
        }

        int targe_against_clinet_11() {
            bs.clear();
            if (interface.empty()) {
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            cout << "Enter MAC: ";
            cin >> deauthspecific_mac;
            cout << "Enter client MAC: ";
            cin >> deauthspecific_client;
            run_cmd({
                "sudo",
                "aireplay-ng",
                "--deauth",
                "0",
                "-a",
                deauthspecific_mac,
                "-c",
                deauthspecific_client,
                interface,
            });
            return 0;
        }

        int crack_wpa_12() {
            bs.clear();
            run_cmd({
                "ls",
                "output"
            });
            cout << "Enter output file: ";
            cin >> aircrack_output;

            run_cmd({
                "ls",
                "psw"
            });
            cout << "Enter the password list: ";
            cin >> aircrack_list;

            string x = outputpath + aircrack_output;
            string y = wordliestpath + aircrack_list;
            
            bs.clear();
            run_cmd({
                "sudo",
                "aircrack-ng",
                x,
                "-w",
                y
            });
            cin >> enter_var;
            return 0;
        }

        int fake_access_point_13() {
            bs.clear();
            if (interface.empty()) {
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            cout << "Create Wifi name: ";
            cin >> airbase_name;
            cout << "Enter channel 1-11: ";
            cin >> airbase_channel;
            run_cmd({
                "sudo",
                "airbase-ng",
                "-e",
                airbase_name,
                "-c",
                airbase_channel,
                interface,
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;
        }

        int visualize_network_14() {
            bs.clear();
            run_cmd({
                "ls",
                "output"
            });
            cout << "Enter .csv file: ";
            cin >> airgraph_csv;
            cout << "Enter output name: ";
            cin >> airgraph_outputname;
            airgraph_csv = outputpath + airgraph_csv;
            airgraph_outputname = outputpath + airgraph_outputname;
            run_cmd({
                "sudo",
                "airgraph-ng",
                "-i",
                airgraph_csv,
                "-o",
                airgraph_outputname,
                "-g",
                "CAPR",
            });
            return 0;
        }

        int displays_wpa_capable_15() {
            bs.clear();
            if (interface.empty()) {
                cout << "No interface selected!";
                sleep(3);
                return 1;
            };
            run_cmd({
                "sudo",
                "wash",
                "-i",
                interface
            });
            cout << "Anything for menu: ";
            cin >> enter_var;
            return 0;
        }

        int reset_output_folder_16() {
            run_cmd({
                "rm",
                "-rf",
                "output",
            });
            run_cmd({
                "mkdir",
                "output"
            });
            return 0;
        }
};

backend_settings backend;