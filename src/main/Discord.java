package main;

import database.*;
import app.*;
import java.util.Scanner;
import java.util.Calendar;


public class Discord 
{
    private static Database data = new Database();
    private static Scanner input = new Scanner(System.in);
    private static Scanner wait = new Scanner(System.in);

    private static void printStartMenu()
    {
        System.out.println(" _____________________________________________");
        System.out.println("|            Welcome to Discord!              |"); 
        System.out.println("|  [1]: Sign in to your account               |");
        System.out.println("|  [2]: Register a new account                |");
        System.out.println("|  [3]: Exit                                  |");
        System.out.println("|                                             |");
        System.out.println("|  [4]: About us                              |");
        System.out.println("|_____________________________________________|");
    }

    private static void printUserMenu()
    {
        System.out.println(" _____________________________________________");
        System.out.println("|  [0]: Logoff                                |");
        System.out.println("|  [1]: View a profile                        |");
        System.out.println("|  [2]: List your friends                     |");
        System.out.println("|  [3]: Add a new friend                      |");
        System.out.println("|  [4]: Send a direct message                 |");
        System.out.println("|  [5]: List/View info about your servers     |");
        System.out.println("|  [6]: Send message in a server              |");
        System.out.println("|  [7]: Settings                              |");
        System.out.println("|  [8]: Join/Create a server                  |");
        System.out.println("|  [9]: Leave a server                        |");
        System.out.println("|  [10]: Delete a friend                      |");
        System.out.println("|                                             |");
        System.out.println("|  [11]: Clean your screen                    |");
        System.out.println("|_____________________________________________|");
    }

    private static void printSettingsMenu()
    {
        System.out.println(" _____________________________________________");
        System.out.println("|  [1]: Change your name                      |");
        System.out.println("|  [2]: Change your image                     |");
        System.out.println("|  [3]: Change your 'about me'                |");
        System.out.println("|  [4]: Change your password                  |");
        System.out.println("|  [5]: Change your e-mail                    |");
        System.out.println("|                                             |");
        System.out.println("|  [6]: Return to menu                        |");
        System.out.println("|_____________________________________________|");
    }

    private static void printServerOptions()
    {
        System.out.println(" _____________________________________________");
        System.out.println("|  [1]: Join an existing server               |");
        System.out.println("|  [2]: Create a new server                   |");
        System.out.println("|                                             |");
        System.out.println("|  [3]: Return                                |");
        System.out.println("|_____________________________________________|");
    }

    private static void printPerfilOptions()
    {
        System.out.println(" _____________________________________________");
        System.out.println("|  [1]: View your profile                     |");
        System.out.println("|  [2]: View a friend's profile               |");
        System.out.println("|                                             |");
        System.out.println("|  [3]: Return                                |");
        System.out.println("|_____________________________________________|");
    }

    private static void clearBuffer(Scanner scanner) 
    {
        if (scanner.hasNextLine()) 
        {
            scanner.nextLine();
        }
    }

    private static void clearScreen()
    {
        try 
        {
            new ProcessBuilder("cmd", "clear", "/c", "cls").inheritIO().start().waitFor();
        } 
        catch (Exception e) 
        {
            System.out.println("[System] The screen couldn't be cleaned. " + e.getMessage());
        }
    }
    
    public static void main(String[] args) 
    {
        Calendar dateToday = Calendar.getInstance();
        clearScreen();
        data.initializeData();
        
        boolean logged = false;
        String system;
        User loggedUser = null;
        
        do
        {   
            //clearScreen();
            if (data.getStatus())
                System.out.println("[System] The database has been initiliazed successfully.");
            else 
                System.out.println("[ERROR] Something went wrong with database.");
            printStartMenu();
            System.out.print(">> ");
            system = input.next();

            switch (system)
            {
                case "1": // login
                    System.out.print("[!] User: ");
                    String user = input.next();
                    
                    User p = data.findUser(user);
                    if (p != null)
                    {
                        System.out.print("[!] Password: ");
                        String password = input.next();
                        if (password.equalsIgnoreCase(p.getPassword()))
                        {
                            loggedUser = p;
                            logged = true;
                        }
                        else 
                        {
                            System.out.println("[System] Wrong password.");
                            System.out.print("[System] Press enter to continue...");
                            clearBuffer(input);
                            input.nextLine();
                        }
                    }
                    else
                    {
                        System.out.printf("[System] The user '%s' couldn't be found in our database. Try to register a new user.\n", user);
                        System.out.println("[System] Press enter to continue...");
                        wait.nextLine();
                    }

                    if (logged == true)
                    {
                        String option;
                        do 
                        {
                            clearScreen();
                            System.out.printf("[System] Welcome, %s!\n", loggedUser.getName());
                            System.out.printf("[System] Date: %d/%d/%d\n", dateToday.get(Calendar.DAY_OF_MONTH), dateToday.get(Calendar.MONTH)+1, dateToday.get(Calendar.YEAR));
                            System.out.println("[System] Select one option:");
                            printUserMenu();
                            System.out.print(">> ");
                            option = input.next();
                            switch (option)
                            {

                                case "0": // logoff
                                    clearScreen();
                                    System.out.println("[System] Disconnected. See you soon!");
                                    logged = false;
                                    loggedUser = null;
                                    break;
                                case "1": // see user's perfil
                                    //clearScreen();
                                    String perfilOption;
                                    do
                                    {
                                        clearScreen();
                                        System.out.println("[System] You chose '1: View a profile':");
                                        printPerfilOptions();
                                        System.out.print(">> ");
                                        perfilOption = input.next();
                                        switch (perfilOption)
                                        {
                                            case "1": // view my perfil
                                            clearScreen();
                                                System.out.println("[System] You chose '1.1: View your profile':");
                                                System.out.println("[System] OBS: If you want to change any information, go to option '7'.\n");
                                                System.out.printf("[-] Name: %s\n", loggedUser.getName());
                                                System.out.printf("[-] User: %s\n", loggedUser.getUser());
                                                System.out.printf("[-] Joined in: %s\n", loggedUser.getDtCreated());
                                                System.out.printf("[-] Image link: %s\n", loggedUser.getImageLink());
                                                if (loggedUser.getAboutMe() == null)
                                                    System.out.println("[-] About you: (go to settings)\n");
                                                else 
                                                    System.out.printf("[-] About you: %s\n\n", loggedUser.getAboutMe());
                                                System.out.print("[System] Press enter to continue...");
                                                clearBuffer(input);
                                                input.nextLine();
                                                break;
                                            case "2": // view a friend perfil
                                                clearScreen();
                                                System.out.println("[System] You chose '1.2: View a friend's profile':");
                                                if (loggedUser.getAmountFriends() == 0)
                                                {
                                                    System.out.println("[System] You don't have any friends yet.");
                                                }
                                                else 
                                                {
                                                    System.out.printf("[System] List of friends: (%d)\n\n", loggedUser.getAmountFriends());
                                                    User[] friends = loggedUser.getFriends();
                                                    for (int i = 0; i < loggedUser.getAmountFriends(); i++)
                                                    {
                                                        System.out.printf("[%d] %s (user: %s)\n", i+1, friends[i].getName(), friends[i].getUser());
                                                    }

                                                    System.out.print("\n[System] Enter the user you want to view profile: ");
                                                    String profileUser = input.next();
                                                    User viewProfile = loggedUser.findUser(profileUser);
                                                    if (viewProfile != null)
                                                    {
                                                        System.out.printf("\n[-] Name: %s\n", viewProfile.getName());
                                                        System.out.printf("[-] User: %s\n", viewProfile.getUser());
                                                        System.out.printf("[-] Joined in: %s\n", viewProfile.getDtCreated());
                                                        System.out.printf("[-] Image link: %s\n", viewProfile.getImageLink());
                                                        if (viewProfile.getAboutMe() == null)
                                                            System.out.println("[-] About: (none)");
                                                        else 
                                                            System.out.printf("[-] About: %s\n\n", viewProfile.getAboutMe());
                                                    }
                                                    else 
                                                        System.out.printf("[System] You and '%s' aren't friends yet.\n", profileUser);
                                                }
                                                System.out.println("\n[System] Press enter to continue...");
                                                wait.nextLine();
                                                break; 
                                            case "3": // return
                                                break;
                                            default:
                                                //System.out.println("[System] Invalid option, try again.");
                                                break;
                                        }
                                    }
                                    while (!perfilOption.equalsIgnoreCase("3"));
                                    break;
                                case "2": // list friends
                                    clearScreen();
                                    System.out.println("[System] You chose '2: List your friends'\n");
                                    if (loggedUser.getAmountFriends() == 0)
                                    {
                                        System.out.println("[System] You don't have any friends yet.");
                                    }
                                    else 
                                    {
                                        User[] friends = loggedUser.getFriends();
                                        for (int i = 0; i < loggedUser.getAmountFriends(); i++)
                                        {
                                            System.out.printf("[%d] %s (user: %s)\n", i+1, friends[i].getName(), friends[i].getUser());
                                        }
                                        System.out.println("");
                                    }
                                    System.out.print("[System] Press enter to continue...");
                                    clearBuffer(input);
                                    input.nextLine();
                                    break;
                                case "3": // add new friend
                                    clearScreen();
                                    System.out.println("[System] You chose '3: Add new friend'");
                                    System.out.print("[System] Enter the user you want to add in your friend list: ");
                                    String addNewFriend = input.next();
                                    User newFriend = data.findUser(addNewFriend);
                                    User alreadyFriend = null;
                                    if (newFriend != null)
                                    {
                                        alreadyFriend = loggedUser.findUser(addNewFriend);
                                        if (alreadyFriend == null) // not friends yet
                                        {
                                            loggedUser.addFriend(newFriend);
                                            newFriend.addFriend(loggedUser);
                                            System.out.printf("[System] You and '%s' are friends now!\n", newFriend.getName());
                                        }
                                        else 
                                            System.out.printf("[System] You and '%s' are already friends!\n", newFriend.getName());
                                    }
                                    else 
                                        System.out.printf("[System] The user '%s' couldn't be found in our database.\n", addNewFriend);
                                    System.out.print("[System] Press enter to continue...");
                                    clearBuffer(input);
                                    input.nextLine();
                                    break;
                                case "4": // send a direct message
                                    clearScreen();
                                    System.out.println("[System] You chose '4: Send a direct message'");
                                    if (loggedUser.getAmountFriends() > 0)
                                    {
                                        System.out.printf(("[System] List of friends: (%d)\n\n"), loggedUser.getAmountFriends());
                                        User[] friends = loggedUser.getFriends();
                                        for (int i = 0; i < loggedUser.getAmountFriends(); i++)
                                        {
                                            System.out.printf("[%d] - %s (user: %s)\n", i+1, friends[i].getName(), friends[i].getUser());
                                        }
                                        System.out.println("\n[System] Enter the user you want to send a direct message: ");
                                        String user3 = input.next();
                                        int exists = 0;

                                        for (int i = 0; i < loggedUser.getAmountFriends(); i++)
                                        {
                                            if (user3.equalsIgnoreCase(friends[i].getUser()))
                                                exists = 1;
                                        }
                                        if (exists == 1)
                                        {
                                            User receiver = data.findUser(user3);
                                            String message;
                                            String date = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
                                            Chat dm;
                                            if (data.findChat(loggedUser.getUser(), user3) == null)
                                            {
                                                dm = new Chat(loggedUser, receiver);
                                                data.newChatUsers(dm);
                                            }
                                            else
                                            {
                                                dm = data.findChat(loggedUser.getUser(), user3);
                                                if (dm.getAmountMessages() > 0)
                                                {
                                                    Message[] lastMessages = dm.getLastMessages();
                                                    System.out.println("\n[System] Last messages...\n");
                                                    for (int i = 0; i < dm.getAmountMessages(); i++)
                                                    {
                                                        System.out.printf("[%s] (%s -> %s): %s\n", lastMessages[i].getDate(), lastMessages[i].getSender(), lastMessages[i].getReceiver(), lastMessages[i].getMessage());
                                                    }
                                                    System.out.println("");
                                                }
                                            } 
                                            
                                            System.out.print("[!] Enter the message, or prompt 'exit' to return to the menu:\n>> ");
                                            clearBuffer(input);
                                            message = input.nextLine();
                                            while (!message.equalsIgnoreCase("exit"))
                                            {
                                                if (!message.equalsIgnoreCase("exit") && message.length() > 0)
                                                {
                                                    dm.sendMessage(loggedUser, receiver, message);
                                                    System.out.printf("[%s] (%s -> %s): %s\n", date, loggedUser.getName(), receiver.getName(), message);
                                                }
                                                System.out.print(">> ");
                                                message = input.nextLine();
                                            }
                                        }
                                        else 
                                        {
                                            System.out.printf("[System] You and '%s' aren't friends yet. Change it by choosing the option '3- Add a new friend' in menu.\n", user3);
                                        }
                                    }
                                    else
                                        System.out.println("[System] You don't have any friends to send a message. Change it by choosing the option '3- Add a new friend' in menu.");
                                    System.out.println("[System] Press enter to return...");
                                    wait.nextLine();
                                    break;
                                case "5": // list and view servers info
                                    clearScreen();
                                    System.out.println("[System] You chose '5: List and view your servers'");
                                    if (loggedUser.getAmountServers() > 0)
                                    {
                                        System.out.printf("[System] You are in '%s' servers: \n\n", loggedUser.getAmountServers());
                                        Server[] list = loggedUser.getServers();
                                        for (int i = 0; i < loggedUser.getAmountServers(); i++)
                                        {
                                            System.out.printf("[%d] %s\n[%d] Members: %d\n\n", i+1, list[i].getName(), i+1, list[i].getAmountUsers());
                                        }

                                        System.out.println("[System] Enter the name of the server you want to see more informations ");
                                        System.out.println("[System] Tip: You can type 'cancel' in any moment to return.");
                                        System.out.print(">> ");
                                        clearBuffer(input);
                                        String viewServer = input.nextLine();
                                        Server viewServer2 = loggedUser.findServer(viewServer);

                                        while (!viewServer.equalsIgnoreCase("cancel") && viewServer2 == null)
                                        {
                                            System.out.printf("[System] You aren't in any server named '%s', try again.\n>> ", viewServer);
                                            viewServer = input.nextLine();
                                            viewServer2 = loggedUser.findServer(viewServer);
                                        }

                                        if (!viewServer.equalsIgnoreCase("cancel"))
                                        {
                                            System.out.printf("\n[-] Server name: %s\n", viewServer2.getName());
                                            System.out.printf("[-] Founded in: %s\n", viewServer2.getDtCreated());
                                            System.out.printf("[-] List of members: (%d)\n\n", viewServer2.getAmountUsers());
                                            User[] listOfUsers = viewServer2.getUsers();

                                            for (int i = 0; i < viewServer2.getAmountUsers(); i++)
                                            {
                                                System.out.printf("    [%d] %s (user: %s)\n", i+1, listOfUsers[i].getName(), listOfUsers[i].getUser());
                                            }
                                            System.out.println("");
                                        }

                                    }
                                    else 
                                        System.out.println("[System] You aren't member of any server. You can create or join in one with the option '8'");
                                    System.out.print("[System] Press enter to continue...");
                                    wait.nextLine();
                                    break;
                                case "6": // send message in a server
                                    clearScreen();
                                    String message = new String();
                                    String date = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
                                    System.out.println("[System] You chose '6: Send message in a server'");
                                    if (loggedUser.getAmountServers() > 0)
                                    {
                                        System.out.printf("[System] Enter the name of the server you want to send message: \n\n", loggedUser.getAmountServers());
                                        Server[] list = loggedUser.getServers();
                                        String sendServer;
                                        for (int i = 0; i < loggedUser.getAmountServers(); i++)
                                        {
                                            System.out.printf("[%d] Server name: %s\n[%d] Founded in: %s\n[%d] Amount of members: %d\n\n", i+1, list[i].getName(), i+1, list[i].getDtCreated(), i+1, list[i].getAmountUsers());
                                        }
                                        System.out.print(">> ");
                                        Server sendServer2 = null;
                                        clearBuffer(input);
                                        do
                                        {
                                            sendServer = input.nextLine();
                                            sendServer2 = loggedUser.findServer(sendServer);
                                            if (sendServer2 == null && sendServer.equalsIgnoreCase("exit") == false)
                                                System.out.printf("[System] You aren't member of a server named '%s'. Try again, or type 'exit' tor return: \n>> ", sendServer);
                                        }
                                        while (sendServer2 == null && sendServer.equalsIgnoreCase("exit") == false);

                                        if (sendServer2 != null)
                                        {
                                            Chat serverChat = sendServer2.getChat();
                                            Message[] lastMessages = serverChat.getLastMessages();
                                            if (serverChat.getAmountMessages() > 0)
                                            {
                                                System.out.println("\n[System] Last messages...\n");
                                                for (int i = 0; i < serverChat.getAmountMessages(); i++)
                                                {
                                                    System.out.printf("[%s] %s (%s) | %s: %s\n", lastMessages[i].getDate(), sendServer2.getName(), serverChat.getChatName(), lastMessages[i].getSender(), lastMessages[i].getMessage());
                                                }
                                                System.out.println("");
                                            }

                                            // String message;

                                            System.out.print("[!] Enter the message, or prompt 'exit' to return to the menu: ");
                                            message = input.nextLine();
                                            while (!message.equalsIgnoreCase("exit"))
                                            {
                                                if (!message.equalsIgnoreCase("exit") && message.length() > 0)
                                                {
                                                    serverChat.sendServerMessage(loggedUser, message);
                                                    System.out.printf("[%s] %s (%s) | %s: %s\n", date, sendServer2.getName(), serverChat.getChatName(), loggedUser.getName(), message);

                                                }
                                                System.out.print(">> ");
                                                message = input.nextLine();
                                            }
                                        }
                                    }
                                    else 
                                        System.out.println("[System] You aren't in any server yet. Create one or join in a existent with option '8'");
                                    System.out.println("[System] Press enter to return...");
                                    //clearBuffer(input);
                                    wait.nextLine();
                                    break; 
                                case "7": // settings - name / image / about me / password / email
                                    String settsOp;
                                    do 
                                    {
                                        clearScreen(); 
                                        System.out.println("[System] You chose '7: Settings:'");
                                        System.out.println("[System] Select the information you want to change: ");
                                        printSettingsMenu();
                                        System.out.print(">> ");
                                        settsOp = input.next();
                                        switch (settsOp)
                                        {
                                            case "1": // change name
                                                clearScreen();
                                                System.out.print("[System] Enter the new name you want: ");
                                                clearBuffer(input);
                                                String newInfo = input.nextLine();
                                                loggedUser.setName(newInfo);
                                                System.out.println("\n[System] Changes applied.");
                                                System.out.println("[System] Press enter to continue...");
                                                //clearBuffer(input);
                                                input.nextLine();
                                                clearScreen();
                                                break;
                                            case "2": // change image
                                                clearScreen();
                                                System.out.print("[System] Enter the image link of the new image: ");
                                                clearBuffer(input);
                                                String newInfo2 = input.next();
                                                loggedUser.setImage(newInfo2);
                                                System.out.println("\n[System] Changes applied.");
                                                System.out.println("[System] Press enter to continue...");
                                                clearBuffer(input);
                                                input.nextLine();
                                                clearScreen();
                                                break;
                                            case "3": // change about me
                                                clearScreen();
                                                System.out.print("[System] Enter your description to 'about me': ");
                                                clearBuffer(input);
                                                String newInfo3 = input.nextLine();
                                                loggedUser.setAboutMe(newInfo3);
                                                System.out.println("\n[System] Changes applied.");
                                                System.out.println("[System] Press enter to continue...");
                                                wait.nextLine();
                                                clearScreen();
                                                break;
                                            case "4": // change password
                                                clearScreen();
                                                String oldPassword;
                                                do 
                                                {
                                                    System.out.print("[System] Enter your current password: ");
                                                    oldPassword = input.next();
                                                    if (!oldPassword.equalsIgnoreCase(loggedUser.getPassword()) && !oldPassword.equalsIgnoreCase("cancel"))
                                                        System.out.println("[System] Wrong password... Enter the right password or type 'cancel' to return: ");

                                                }
                                                while (oldPassword.equalsIgnoreCase(loggedUser.getPassword()) == false && oldPassword.equalsIgnoreCase("cancel") == false);

                                                if (!oldPassword.equalsIgnoreCase("cancel"))
                                                {
                                                    System.out.print("[System] Enter the new password: ");
                                                    String newPassword = input.next();
                                                    loggedUser.setPassword(newPassword);
                                                    System.out.println("\n[System] Password updated.");
                                                }
                                                System.out.println("[System] Press enter to continue...");
                                                clearBuffer(input);
                                                input.nextLine();
                                                clearScreen();
                                                break;
                                            case "5": // change email
                                                clearScreen();
                                                System.out.print("[System] Enter the new e-mail: ");
                                                clearBuffer(input);
                                                String newInfo4 = input.next();
                                                loggedUser.setEmail(newInfo4);
                                                System.out.println("\n[System] Changes applied.");
                                                System.out.println("[System] Press enter to continue...");
                                                clearBuffer(input);
                                                input.nextLine();
                                                clearScreen();
                                                break;
                                            case "6": // return
                                                break;
                                            default:
                                                //System.out.println("[System] Invalid option, try again.");
                                                break;
                                        }
                                    }
                                    while (!settsOp.equalsIgnoreCase("6"));
                                    System.out.println("[System] Press enter to continue...");
                                    clearBuffer(input);
                                    input.nextLine();
                                    break;
                                case "8": // create a server
                                    clearScreen();
                                    String serverOptions;
                                    Server[] servers = data.getServers();
                                    do 
                                    {
                                        System.out.println("[System] You chose '8: Join/Create a server'");
                                        printServerOptions();
                                        System.out.print(">> ");
                                        serverOptions = input.next();

                                        switch (serverOptions)
                                        {

                                            case "1": // Join an existing server
                                                clearScreen();
                                                System.out.println("[System] You chose '8.1: Join an existing server'");
                                                String nameOfServer;
                                                if (data.getAmountServers() > 0)
                                                {
                                                    if (loggedUser.getAmountServers() < 10)
                                                    {
                                                        
                                                        System.out.println("[System] Here is the list of servers in our database: \n");
                                                        for (int i = 0; i < data.getAmountServers(); i++)
                                                        {
                                                            System.out.printf("[%d] Server name: %s\n", i+1, servers[i].getName());
                                                            System.out.printf("[%d] Founded in: %s\n", i+1, servers[i].getDtCreated());
                                                            System.out.printf("[%d] Amount members: %d\n\n", i+1, servers[i].getAmountUsers());
                                                        }
    
                                                        System.out.print("[System] Enter the name of the server you want to join: (or type 'cancel' to return): ");
                                                        clearBuffer(input);
                                                        nameOfServer = input.nextLine();
    
                                                        Server server = data.findServer(nameOfServer);
    
                                                        if (server != null)
                                                        {
                                                            if (server.addUser(loggedUser))
                                                            {
                                                                System.out.printf("[System] You are now a member of the server '%s'!\n", server.getName());
                                                            }
                                                            else 
                                                            {
                                                                System.out.printf("[System] You are already a member of the server '%s'!\n", server.getName());
                                                            }
                                                        }
                                                        else 
                                                        {
                                                            if(!nameOfServer.equalsIgnoreCase("cancel"))
                                                                System.out.printf("[System] The server '%s' doesn't exist in our database.\n", nameOfServer);
                                                        }
                                                    }
                                                    else 
                                                        System.out.println("[System] You have reached the server limit for one user (10).");
                                                }
                                                else
                                                {
                                                    System.out.println("[System] There's not any server in our database. You can create the first one!");
                                                }
                                                System.out.println("[System] Press enter to continue...");
                                                wait.nextLine();
                                                clearScreen();
                                                break;
                                            case "2": // create a new server
                                                clearScreen();
                                                System.out.println("[System] You chose '8.2: Create a new server'\n");
                                                System.out.print("[System] Enter the name of the new server: ");
                                                clearBuffer(input);
                                                String newServerName = input.nextLine();
                                                Server createServer = data.findServer(newServerName);
                                                if (createServer == null)
                                                {
                                                    System.out.print("[System] Enter the image link of the server: ");
                                                    String newServerImage = input.next();
                                                    String newServerDate = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
                                                    createServer = new Server(newServerName, newServerImage, newServerDate);
                                                    if (data.newServer(createServer))
                                                    {
                                                        createServer.addUser(loggedUser);
                                                        System.out.printf("[System] The server '%s' has been created successfully.\n", createServer.getName());
                                                    }
                                                    else 
                                                        System.out.println("[System] We were unable to create a new server as our database is full.");
                                                }
                                                else 
                                                    System.out.println("[System] A server with this name already exists.");
                                                System.out.println("[System] Press enter to continue...");
                                                wait.nextLine();
                                                clearScreen();
                                                break; 
                                            case "3":
                                                break;
                                            default:
                                                break;
                                        }
                                    }
                                    while (!serverOptions.equalsIgnoreCase("3"));
                                    System.out.println("[System] Press enter to continue...");
                                    clearBuffer(input);
                                    input.nextLine();
                                    break;
                                case "9": // leave server
                                    clearScreen();
                                    System.out.println("[System] You chose '9: Leave a server'");
                                    if (loggedUser.getAmountServers() > 0)
                                    {
                                        System.out.printf("[System] List of your servers: (%d) \n\n", loggedUser.getAmountServers());
                                        
                                        Server[] list = loggedUser.getServers();
                                        for (int i = 0; i < loggedUser.getAmountServers(); i++)
                                        {
                                            System.out.printf("[%d] Server name: %s\n[%d] Founded in: %s\n[%d] Amount of members: %d\n\n", i+1, list[i].getName(), i+1, list[i].getDtCreated(), i+1, list[i].getAmountUsers());
                                        }
                                        
                                        System.out.print("[System] Enter the name of the server you want to leave: ");
                                        clearBuffer(input);
                                        String exitServer = input.nextLine();
                                        Server exitServer2 = loggedUser.findServer(exitServer);

                                        if (exitServer2 != null)
                                        {
                                            loggedUser.leaveServer(exitServer2);
                                            System.out.printf("[System] You are no longer a member of '%s'.\n", exitServer2.getName());
                                        }
                                        else 
                                            System.out.printf("[System] You aren't a member of any server named '%s'.\n", exitServer);
                                    }
                                    else 
                                        System.out.println("[System] You aren't member of any server yet.");
                                    System.out.println("[System] Press enter to continue...");
                                    wait.nextLine();
                                    break;
                                case "10": // delete a friend
                                    clearScreen();
                                    System.out.println("[System] You chose '10: Delete a friend'");
                                    if (loggedUser.getAmountFriends() > 0)
                                    {
                                        System.out.println("[System] List of your friends:\n");
                                        String userToDelete;

                                        User[] friends = loggedUser.getFriends();
                                        for (int i = 0; i < loggedUser.getAmountFriends(); i++)
                                        {
                                            System.out.printf("[%d] %s (user: %s)\n", i+1, friends[i].getName(), friends[i].getUser());
                                        }
                                        System.out.print("\n[System] Enter the user you want to remove from your friends list: ");
                                        userToDelete = input.next();

                                        User delete = loggedUser.findUser(userToDelete);

                                        if (delete != null)
                                        {
                                            loggedUser.deleteFriend(delete);
                                            System.out.printf("[System] You and '%s' are no longer friends.\n", delete.getUser());
                                        }
                                        else 
                                            System.out.printf("[System] You and '%s' aren't friends yet.\n", userToDelete);
                                    }
                                    else 
                                        System.out.println("[System] You don't have any friends yet.");
                                    System.out.println("[System] Press enter to continue...");
                                    wait.nextLine();
                                    break;
                                case "11":
                                    clearScreen();
                                    break;
                                default:
                                    System.out.println("[System] Invalid option, try again.");
                                    break;
                            }
                        }
                        while (!option.equalsIgnoreCase("0"));
                    }
                    break;
                case "2": // register
                    System.out.println("[System] We're happy to have you here! Let's start your registration.");
                    System.out.println("[System] Tip: You can type 'cancel' in any moment to return to main menu.\n");
                    String newUser;
                    int checkUser = 0;
                    User[] check = data.getUsers();
                    System.out.print("[!] Enter your new user: ");
                    do 
                    {
                        checkUser = 0;
                        newUser = input.next();
                        for (int i = 0; i < data.getAmountUsers(); i++)
                        {
                            if (check[i].getUser().equalsIgnoreCase(newUser))
                                checkUser = 1;
                        }

                        if (checkUser == 1 && !newUser.equalsIgnoreCase("exit"))
                        {
                            System.out.printf("[System] The user '%s' is already in use. Try another, or type 'cancel' to return: ", newUser);
                        }

                    }
                    while (checkUser != 0 && !newUser.equalsIgnoreCase("cancel"));

                    if (checkUser == 0 && newUser.equalsIgnoreCase("cancel") == false)
                    {
                        System.out.print("[!] Enter your name ");
                        clearBuffer(input);
                        String name = input.nextLine();
                        if (!name.equalsIgnoreCase("cancel"))
                        {
                            
                            System.out.print("[!] Enter your password ");
                            String passwordNewUser = input.next();
                            if (!passwordNewUser.equalsIgnoreCase("cancel"))
                            {

                                String confirmPassword;
                                do
                                {
                                    System.out.print("[!] Confirm the passsword: ");
                                    confirmPassword = input.next();
                                    if (confirmPassword.equalsIgnoreCase(passwordNewUser) == false)
                                        System.out.println("[!] The passwords must be identics.");
                                }
                                while (!confirmPassword.equalsIgnoreCase(passwordNewUser) && !confirmPassword.equalsIgnoreCase("cancel"));

                                if (!confirmPassword.equalsIgnoreCase("cancel"))
                                {

                                    System.out.print("[!] Enter your e-mail: ");
                                    String email = input.next();

                                    if (!email.equalsIgnoreCase("cancel"))
                                    {

                                        System.out.print("[!] Enter your image link: ");
                                        String image = input.next();
                                        if (!image.equalsIgnoreCase("cancel"))
                                        {

                                            String date = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
                                            User newUser1 = new User(newUser, image, date, name, email, passwordNewUser);
                                            if (data.newUser(newUser1))
                                            {
                                                System.out.println("[System] Successfully registered. Now you must log-in.");
                                            }
                                            else 
                                                System.out.println("[System] Ops, our database is full. Try again later.");
                                        }
                                    }
                                }
                            }
                        }
                    }
                    System.out.println("[System] Press enter to continue...");
                    wait.nextLine();      
                    break;
                case "3":
                    clearScreen();
                    System.out.println("[System] Thanks for using our app.");
                    System.out.println("[System] Orientação a Objetos - 2023.2");
                    break;
                case "4": // about us
                    System.out.println("[+] Our team:\n");
                    System.out.println("    [-] Diogo Ferreira (221008570) - user: diogo.ferreira");
                    System.out.println("\n[+] College work done in 2023, second semester, under\nthe supervision of Fabiana Mendes.\n");
                    System.out.println("[System] Press enter to continue...");
                    clearBuffer(input);
                    input.nextLine();
                    //clearScreen();
                    break;
                default:
                    System.out.println("[System] Invalid option, try again.");
                    System.out.println("[System] Press enter to continue...");
                    wait.nextLine();
                    clearScreen();
                    break;
            }
        }
        while (!system.equalsIgnoreCase("3"));
        input.close();
    }    


}
