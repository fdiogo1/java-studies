package app;


public class User extends New implements Search
{
    private String user;
    private String email;
    private String password;
    private Server[] servers = new Server[10];
    private int amountServers = 0;
    private User[] friends = new User[20];
    private int amountFriends = 0;
    private String aboutMe = null;

    public User (String user, String image, String dtCreated, String name, String email, String password)
    {
        super(name, image, dtCreated);
        this.user = user;
        this.email = email;
        this.password = password;
    }

    public String getUser()
    {
        return user;
    }

    
    public String getEmail()
    {
        return email;
    }

    public String getPassword()
    {
        return password;
    }
    
    public Server[] getServers()
    {
        return servers;
    }

    public int getAmountServers()
    {
        return amountServers;
    }

    public User[] getFriends()
    {
        return friends;
    }

    public int getAmountFriends()
    {
        return amountFriends;
    }

    public String getAboutMe()
    {
        return aboutMe;
    }

    public void setEmail(String newEmail)
    {
        this.email = newEmail;
    }

    public void setPassword(String newPassword)
    {
        this.password = newPassword;
    }
    
    public boolean joinServer(Server server)
    {
        if (amountServers < 10)
        {
            servers[amountServers++] = server; 
            return true;
        }
        else 
            return false;
    }

    public boolean addFriend(User newFriend)
    {
        if (amountFriends < 20)
        {
            friends[amountFriends++] = newFriend;
            return true;
        }
        else 
            return false;
    }

    public String toString()
    {
        return "Name " + getName() + "\nUser: " + getUser() + "\nE-mail: " + getEmail() + "\n";
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
    
    public boolean leaveServeraaaaaaa(String serverName)
    {
        if (amountServers > 0)
        {
            Server server = findServer(serverName);
            if (server != null)
            {
                // retirar o servidor do usuario
                int j = 0;
                
                Server[] newServers = new Server[10];
                for (int i = 0; i < amountServers; i++)
                {
                    if (servers[i].getName().equalsIgnoreCase(serverName) == false)
                        newServers[j++] = servers[i];
                    }
                    
                    servers = newServers;
                    amountServers--;
                    // retirar o usuario do servidor
                    User[] newUsers = new User[100]; 
                    User[] users = server.getUsers();
                    
                    j = 0;
                    
                    for (int i = 0; i < server.getAmountUsers(); i++)
                    {
                        if (users[i].getUser().equalsIgnoreCase(this.user) == false)
                        newUsers[j++] = users[i];
                    }
                    server.removeOneUser();
                    server.setUsers(newUsers);
                    return true;
                }
                else 
                return false;            
            }
            else
            return false;
    }


    public void deleteFriend(User p)
    {
        // remove from this user
        User[] newFriends = new User[100];
        
        int j = 0;
        for (int i = 0; i < amountFriends; i++)
        {
            if (!p.getUser().equalsIgnoreCase(friends[i].getUser()))
            newFriends[j++] = friends[i];
        }
        
        friends = newFriends;
        amountFriends--;
        
        // remove from the p user
        User[] pFriends = p.getFriends();
        User[] newFriends2 = new User[100];
        j = 0;

        for (int i = 0; i < p.getAmountFriends(); i++)
        {
            if(!pFriends[i].getUser().equalsIgnoreCase(this.user))
                newFriends2[j++] = pFriends[i];
        }

        p.setFriends(newFriends2);
        p.setAmountFriends(j);
    }

    public void setFriends (User[] newFriends)
    {
        friends = newFriends;
    }

    public void setAmountFriends(int newAmountFriends)
    {
        amountFriends = newAmountFriends;
    }
        
    public void leaveServer(Server server)
    {
        // retirar o servidor do usuario
        int j = 0;
            
        Server[] newServers = new Server[100];
        for (int i = 0; i < amountServers; i++)
        {
            if (servers[i].getName().equalsIgnoreCase(server.getName()) == false)
                newServers[j++] = servers[i];
        }
        servers = newServers;
        amountServers--;
        // retirar o usuario do servidor
        User[] newUsers = new User[100]; 
        User[] users = server.getUsers();
            
        j = 0;
            
        for (int i = 0; i < server.getAmountUsers(); i++)
        {
            if (users[i].getUser().equalsIgnoreCase(this.user) == false)
            newUsers[j++] = users[i];
        }
        server.removeOneUser();
        server.setUsers(newUsers);
    }

    public User findUser(String name)
    {
        User result = null;
        for (int i = 0; i < amountFriends; i++)
        {
            if (friends[i].getUser().equalsIgnoreCase(name))
                result = friends[i];
        }
        return result;
    }


    public void setAboutMe(String aboutMe)
    {
        this.aboutMe = aboutMe;
    }

}