#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;



class shortcuts_settings_ui{
    public:

        void clear() {
            system("clear");
        };
        void space() {
            cout << endl;
        };
        
        
 };
shortcuts_settings_ui us;

class menu_ui{
    public:
        string banner = R"(
                            	                     ⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
			    	                   ⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
.##...##...####...##..##...####...######..######. ⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
.###.###..##..##..###.##..##..##..##........##... ⠀⣀⣠⣿⣷⣴⣶⣶⣶⣶⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣧⣀⣀⠀
.##.#.##..##..##..##.###..##..##..####......##... ⢰⣿⡿⠛⠛⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠛⠛⢿⣿⡆
.##...##..##..##..##..##..##..##..##........##... ⣸⣿⠁⠀⣀⡀⠀⢀⡀⠀⢀⡀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠈⣿⣇
.##...##...####...##..##...####...##......######. ⢿⣿⠀⠀⠻⠏⠀⠻⠟⠀⠻⠟⠀⠀⠀⠀⠀⠀⠻⠟⠀⠀⣿⡟
................................................. ⢸⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⡇
					   	  ⠈⠻⠿⣿⣿⣶⣶⣶⣶⣦⣤⣤⣤⣤⣴⣶⣶⣶⣶⣿⣿⠿⠟⠁
						   ⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀)";
        int banner_print() {
            us.clear();
            cout << banner << endl;
            us.space();
            return 0;
        }

        int airmongng_aircrackng_airbaseng() {
            cout << "Airmon-ng                                   " << "Airecrack-ng" << endl;
            cout << "[1] Start  Monitor Mode                     " << "[12] Crack WPA/WPA2 with Wordlist" << endl;
            cout << "[2] Stop Monitor Mode                       " << endl;
            cout << "[3] Shows disturbing processes              " << "Airbase-ng" << endl;
            cout << "[4] Kill disturbing processes               " << "[13] Set up a fake access point" << endl;
            cout << "[5] Start Monitor on specific channel" << endl;
            us.space();
            return 0;
        }

        int interface_airgraphng() {
            cout << "Inerface                                    " << "Airgraph-ng" << endl;
            cout << "[6] Select interface                        " <<  "[14] Visualize network connections" << endl;
            us.space();
            return 0;
        }

        int airodumpng_wash() {
            cout << "Airodump-ng                                 " << "Wash" << endl;
            cout << "[7] Show all networks                       " << "[15] Displays WPS capable networks" << endl;
            cout << "[8] Targeted monitoring" << endl;
            us.space();
            return 0;
        }

        int aireplayng_end() {
            cout << "Aireplay-ng                                 " << "Settings" << endl;
            cout << "[9] Endless deauth                          " << "[16] Delete files in output" << endl;
            cout << "[10] Deauthentication attack                " << "[17] Settings" << endl;
            cout << "[11] Targeted against specific client       " << "[18] Exit" << endl;
            us.space();
            return 0;
        }

        int interface_menu() {
            cout << "Interface" << endl;
            cout << "[1] Select an interfaces" << endl;
            cout << "[2] Show current auto interface" << endl;
            
            return 0;
        }

        void menu_show() {
            banner_print();
            airmongng_aircrackng_airbaseng();
            interface_airgraphng();
            airodumpng_wash();
            aireplayng_end();

        }
};

menu_ui menu;
