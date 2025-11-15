from time import sleep
from colorama import Fore, Style
import os
import subprocess

restart = True
interface = None

if not os.path.exists("output"):
    os.makedirs("output")
    
if not os.path.exists("psw"):
    os.makedirs("psw")
    
    
class shortcuts:
    def main_menu():
        input("Press enter for menu: ")

    def clear():
        os.system("clear")
        
    def airmon_ng():
        subprocess.run(["sudo", "airmon-ng"])

    def space():
        print("")
    
    
class WifiMenu:
    def __init__(self):
        shortcuts.clear()
        self.banner_text =  """					             ⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
			    	                   ⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
.##...##...####...##..##...####...######..######. ⠀⠀⠀⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀
.###.###..##..##..###.##..##..##..##........##... ⠀⣀⣠⣿⣷⣴⣶⣶⣶⣶⣿⣿⣿⣿⣶⣶⣶⣶⣶⣿⣧⣀⣀⠀
.##.#.##..##..##..##.###..##..##..####......##... ⢰⣿⡿⠛⠛⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠉⠉⠉⠉⠛⠛⢿⣿⡆
.##...##..##..##..##..##..##..##..##........##... ⣸⣿⠁⠀⣀⡀⠀⢀⡀⠀⢀⡀⠀⠀⠀⠀⠀⠀⢀⣀⠀⠈⣿⣇
.##...##...####...##..##...####...##......######. ⢿⣿⠀⠀⠻⠏⠀⠻⠟⠀⠻⠟⠀⠀⠀⠀⠀⠀⠻⠟⠀⠀⣿⡟
................................................. ⢸⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣿⡇
					   	  ⠈⠻⠿⣿⣿⣶⣶⣶⣶⣦⣤⣤⣤⣤⣴⣶⣶⣶⣶⣿⣿⠿⠟⠁
						   ⠀⠀⠀⠀⠀⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠉⠀"""

    def banner(self):
        shortcuts.clear()
        print(self.banner_text)
        shortcuts.space()
        
    def airmonng(self):
        print(Style.RESET_ALL + "Airmon-ng")
        print("[1] Start Monitor Mode")
        print("[2] Stop Monitor Mode")
        print("[3] Shows disturbing processes")
        print("[4] Kill disturbing processes")
        print("[5] Start Monitor on specific channel")
        shortcuts.space()
    
    def interfaces(self):
        print("interface")
        print("[6] Select interface")
        shortcuts.space()
        
    def airodumpng(self):
        print("airodump-ng")
        print("[7] Show all networks")
        print("[8] Targeted monitoring")
        shortcuts.space()
        
    def aireplayng(self):
        print("aireplay-ng")
        print("[9] Endless Deauth ")
        print("[10] Deauthentication attack (optional)")
        print("[11] Targeted against specific client")
        shortcuts.space()
        
    def airecrackng(self):
        print("airecrack-ng")
        print("[12] Crack WPA/WPA2 with Wordlist")
        shortcuts.space()
    
    def airbaseng(self):
        print("airbase-ng")
        print("[13] Set up a fake access point")
        shortcuts.space()
    
    def airgraphng(self):
        print("airgraph-ng")
        print("[14] Visualize network connections")
        shortcuts.space()
        
    def wash(self):
        print("wash")
        print("[15] Displays WPS capable networks") 
        shortcuts.space()
        
    def helper(self):
        print("""This program is built entirely around the tools provided by airmon-ng, so please make sure to support its developers. Before you begin, it’s important to understand that most functions in this program can be stopped at any time by pressing Ctrl + C. To get started, you’ll first need to place your wireless interface into monitor mode. This is done using airmon-ng, which is shown at the beginning of the program. Simply follow the on-screen instructions to enable monitor mode on your interface. Once activated, your interface will typically be renamed to something like wlan0mon or wlan1mon.

    Next, press 6 in the menu and select the interface you just switched into monitor mode. This interface will now be used to scan nearby wireless networks if you press 7. Please remember: only attempt to test or attack networks you own or have explicit permission to audit. During the scan, make note of the MAC address and the channel (usually a number between 1 and 13) of the target network. Once you have that information, proceed to step 8 in the program to start monitoring the network. Let the monitoring process run for a while so the necessary handshake data can be captured.

    After that, return to the main menu and choose the "endless deauth" option. Follow the instructions provided by the program carefully. When enough data has been collected, you can check the .cap file (typically located in something like output/output.cap) to see if EAPOL packets have been successfully captured. If no EAPOLs are present, password cracking will not be possible. If they are, proceed to run aircrack-ng. Navigate to the .cap file and select it, then provide your own password list (for example: psw/password-list.txt). If the correct password is in the list, the brute-force process will succeed and reveal it.

    Good luck—and if you have any further questions, feel free to reach out!""")
        
    def end(self):
        print("[16] Delete files in output")
        print("[17] help")
        print("[18] exit")
        
    def show(self):
        self.banner()
        if interface:
                print(Fore.GREEN + f"interface is {interface}")
        else: print(Fore.RED + "No interface is selected")
        self.airmonng()
        self.interfaces()
        self.airodumpng()
        self.aireplayng()
        self.airecrackng()
        self.airbaseng()
        self.airgraphng()
        self.wash()
        self.end()



class modes():
    def start_interface_1():
        shortcuts.clear()
        subprocess.run(["sudo", "airmon-ng"])
        interface_start = input("Enter interface for monitor mode: ")
        subprocess.run(["sudo", "airmon-ng", "start", interface_start])
        sleep(1)
    
    def stop_interface_2():
        shortcuts.clear()
        shortcuts.airmon_ng()
        interface_stop = input("Enter interface to stop: ")
        subprocess.run(["sudo", "airmon-ng", "stop", interface_stop])
        sleep(0)
        
    def show_disturbing_proc_3():
        shortcuts.clear()
        subprocess.run(["sudo", "airmon-ng", "check"])
        shortcuts.main_menu()

    def kill_disturbing_proc_4():
        shortcuts.clear()
        subprocess.run(["sudo", "airmon-ng", "check", "kill"])
        sleep(3)

    def start_interface_channel_5():
        shortcuts.clear()
        shortcuts.airmon_ng()
        interface_start_channel = input("Enter interface: ")
        channel_airmon = input("Enter channel: ")
        subprocess.run(["sudo", "airmon-ng", "start", interface_start_channel, channel_airmon])

    def show_networks_7():
        shortcuts.clear()
        if interface:
            subprocess.run(["sudo", "airodump-ng", interface])
        else:
            print("Please enter an interface first in option 6!")
        shortcuts.main_menu()

    def targeted_monitoring_8():
        shortcuts.clear()
        monitoring_mac = input("Enter MAC: ")
        monitoring_channel = input("Enter channel: ")
        monitoring_output_name = input("Enter output file name: ")
        subprocess.run(["sudo", "airodump-ng","-c", monitoring_channel,"-w", f"output/{monitoring_output_name}","--bssid", monitoring_mac,interface])

    def endless_deauth_9():
        shortcuts.clear()
        endlessdeauth_mac = input("Enter MAC: ")
        subprocess.run(["sudo", "aireplay-ng", "--deauth", "0", "-a", endlessdeauth_mac, interface])

    def deauth_attack_10():
        shortcuts.clear()
        deauthattack_packages = input("Enter how many packages: ")
        deauthattack_mac = input("Enter MAC: ")
        subprocess.run(["sudo", "aireplay-ng", "--deauth", deauthattack_packages, "-a", deauthattack_mac, interface])

    def target_against_client_11():
        shortcuts.clear()
        deauthspecific_mac = input("Enter MAC: ")
        deauthspecific_client = input("Enter client MAC: ")
        subprocess.run(["sudo", "aireplay-ng", "--deauth", "0", "-a", deauthspecific_mac, "-c", deauthspecific_client, interface])

    def crack_wpa2_12():
        shortcuts.clear()
        subprocess.run(["ls", "output"])
        aircrack_output = input("Enter the output Name: ")
        subprocess.run(["ls", "psw"])
        aircrack_list = input("Enter the password list: ")
        shortcuts.clear()
        subprocess.run(["sudo", "aircrack-ng", f"output/{aircrack_output}", "-w", f"psw/{aircrack_list}"])
        shortcuts.main_menu()

    def fake_access_point_13():
        shortcuts.clear()
        airbase_name = input("Enter Wifi name: ")
        airbase_channel = input("Enter channel 1-11: ")
        subprocess.run(["sudo", "airbase-ng", "-e",airbase_name, "-c", airbase_channel, interface])
        shortcuts.main_menu()

    def visualize_network_14():
        shortcuts.clear()
        subprocess.run(["ls", "output"])
        airgraph_csv = input("Enter .csv file: ")
        airgrap_outputname = input("Enter output name: ")
        subprocess.run(["sudo", "airgraph-ng", "-i", f"output/{airgraph_csv}", "-o", f"output/{airgrap_outputname}", "-g", "CAPR"])
        shortcuts.main_menu()

    def displays_wpa_capable_15():
        shortcuts.clear()
        subprocess.run(["sudo", "wash", "-i", interface])
        shortcuts.main_menu()

    def reset_output_folder():
        subprocess.run(["rm", "-rf", "output"])
        subprocess.run(["mkdir", "output"])
        
        

if __name__ == "__main__":
    menu = WifiMenu()
    
    while restart == True:
        try:
            menu.show()
            mode = int(input(": "))
            if mode == 1:
                    modes.start_interface_1()
            elif mode == 2:
                    modes.stop_interface_2()
            elif mode == 3:
                    modes.show_disturbing_proc_3()
            elif mode == 4:
                   modes.kill_disturbing_proc_4()
            elif mode == 5:
                    modes.start_interface_channel_5()
            elif mode == 6:
                    shortcuts.clear()
                    shortcuts.airmon_ng()
                    print("you can change that everytime!")
                    interface = input("Enter the interface for airodump/aireplay/aircrack etc. (like wlan0mon): ")
            elif mode == 7:
                    modes.show_networks_7()
            elif mode == 8:
                    modes.targeted_monitoring_8()
            elif mode == 9:
                    modes.endless_deauth_9()
            elif mode == 10:
                    modes.deauth_attack_10()
            elif mode == 11:
                    modes.target_against_client_11()
            elif mode == 12:
                    modes.crack_wpa2_12()
            elif mode == 13:
                    modes.fake_access_point_13()
            elif mode == 14:
                    modes.visualize_network_14()
            elif mode == 15:
                    modes.displays_wpa_capable_15()
            elif mode == 16:
                    modes.reset_output_folder()
            elif mode == 17:
                    shortcuts.clear()
                    menu.helper()
                    shortcuts.main_menu()
            elif mode == 18:
                    shortcuts.clear()
                    break
        except: KeyboardInterrupt and ValueError

    
    
    