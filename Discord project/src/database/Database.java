package database;

import app.*;

public class Database implements Search
{
    private User[] users;
    private int amountUsers = 0;
    private Server[] servers;
    private boolean status;
    private int amountServers = 0;
    private Chat[] chatsUsers;
    private int amountChatsUsers = 0;

    
    public Database ()
    {
        users = new User[100];
        servers = new Server[100];
        chatsUsers = new Chat[100];
    }
    
    public User[] getUsers() {
        return users;
    }
    
    public int getAmountUsers() {
        return amountUsers;
    }
    
    public Server[] getServers() {
        return servers;
    }
    
    public int getAmountServers() {
        return amountServers;
    }
    
    public Chat[] getChatsUsers() {
        return chatsUsers;
    }
    
    public int getAmountChatsUsers() {
        return amountChatsUsers;
    }

    public void setAmountChatUsers(int newAmountChatUsers)
    {
        this.amountChatsUsers = newAmountChatUsers;
    }

    public void setChatUsers(Chat[] newChats)
    {
        this.chatsUsers = newChats;
    }

    public boolean newUser(User p)
    {
        if (amountUsers < 100)
        {
            users[amountUsers++] = p;
            return true;
        }
        else 
            return false;
    }

    public User findUser(String user)
    {
        User p = null;
        for (int i = 0; i < amountUsers; i++)
        {
            if(users[i].getUser().equalsIgnoreCase(user))
                p = users[i];
        }

        return p; // not found
    }

    public Server findServer(String serverName)
    {
        Server result = null;

        for (int i = 0; i < getAmountServers(); i++)
        {
            if (servers[i].getName().equalsIgnoreCase(serverName))
                result = servers[i];
        }

        return result;
    }

    public void newChatUsers(Chat c)
    {
        chatsUsers[amountChatsUsers++] = c;
    }

    public boolean newServer (Server p)
    {
        if (amountServers < 100)
        {
            servers[amountServers++] = p;
            return true;
        }
        else 
            return false;
    }

    public void initializeData()
    {
        // initializing users
        users[amountUsers++] = new User("diogo.ferreira", "imgur.com", "10/11/2023", "Diogo Ferreira", "pessoaldiogoferreira@gmail.com", "diogo123");
        users[amountUsers++] = new User("guilherme.davila", "imgur.com", "10/11/2023", "Guilherme D'Avila", "guilherme@gmail.com", "gui123");
        users[amountUsers++] = new User("leonardo.castro", "imgur.com", "10/11/2023", "Leonardo Castro", "leo.email@gmail.com", "leo123");
        users[amountUsers++] = new User("fabiana.mendes", "imgur.com", "10/11/2023", "Fabiana Mendes", "fabianamendes@unb.br", "fabiana123");
        
        // initializing servers
        servers[amountServers++] = new Server("Monitoria OO", "imgur.com", "10/11/2023");
        servers[0].addUser(findUser("diogo.ferreira"));
        servers[0].addUser(findUser("guilherme.davila"));
        servers[0].addUser(findUser("leonardo.castro"));
        servers[0].addUser(findUser("fabiana.mendes"));
        servers[amountServers++] = new Server("Amigos", "imgur.com", "10/11/2023");
        servers[1].addUser(findUser("diogo.ferreira"));
        servers[1].addUser(findUser("guilherme.davila"));
        servers[1].addUser(findUser("leonardo.castro"));
        status = true;
    }

    public boolean getStatus()
    {
        return status;
    }

    public Chat findChat(String user1, String user2)
    {
        Chat chat = null;

        for (int i = 0; i < amountChatsUsers; i++)
        {
            if(chatsUsers[i].findUser(user1) != null && chatsUsers[i].findUser(user2) != null)
                chat = chatsUsers[i];
        }

        return chat;    
    }

    public void setUsers(User[] newUsers)
    {
        this.users = newUsers;
    }

    public void setAmountUsers(int newAmountUsers)
    {
        this.amountUsers = newAmountUsers;
    }

    public boolean deleteUser(String user)
    {
        User p = findUser(user);
        if (p != null)
        {
            User[] newUsers = new User[100];
            int j = 0;
            for (int i = 0; i < amountUsers; i++)
            {
                if (!users[i].getUser().equalsIgnoreCase(user))
                    newUsers[j++] = users[i];
            }

            setUsers(newUsers);
            setAmountUsers(amountUsers-1);
        
            return true;
        }   
        else 
            return false;
    }
}
