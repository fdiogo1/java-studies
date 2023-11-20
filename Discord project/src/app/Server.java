package app;

public class Server extends New implements Search
{
    private User[] users;
    private int amountUsers;
    private String serverLink;
    private Chat chat;

    public Server (String name, String image, String dtCreated)
    {
        super(name, image, dtCreated);
        users = new User[10];
        amountUsers = 0;
        chat = new Chat("Main");
    }

    public Chat getServerChat()
    {
        return chat;
    }

    public User[] getUsers()
    {
        return users;
    }

    public String getServerLink()
    {
        return serverLink;
    }

    public int getAmountUsers()
    {
        return amountUsers;
    }

    public boolean addUser(User p)
    {
        // verify if the user is already a member
        for (int i = 0; i < amountUsers; i++)
        {
            if (p.getUser().equalsIgnoreCase(users[i].getUser()))
            {
                return false; // the user already exists in the server
            }
        }
        users[amountUsers++] = p;
        p.joinServer(this);
        return true;
    }
    
    public Chat getChat()
    {
        return chat;
    }


    public User findUser(String user)
    {
        User result = null;
        for (int i = 0; i < amountUsers; i++)
        {
            if(users[i].getUser().equalsIgnoreCase(user))
                result = users[i];
        }
        return result; // not found
    }

    public String toString()
    {
        return "Server name: " + getName() + "\nFounded: " + getDtCreated() + "\nAmount of members: " + getAmountUsers() + "\n";
    }

    public void removeOneUser()
    {
        this.amountUsers--;
    }

    public void setUsers(User[] users)
    {
        this.users = users;
    }
}
