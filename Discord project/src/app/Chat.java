package app;

import java.util.Calendar;

public class Chat implements Search {
    private String chatName = null;
    private User user1 = null;
    private User user2 = null;
    private Message[] message = new Message[1000];
    private int amountMessages = 0;
    private String date;
    
    private static Calendar dateToday = Calendar.getInstance();
    
    public Chat(User a, User b) // between two users
    {
        user1 = a;
        user2 = b;
    }
    
    public Chat(String chatName) // between two users
    {
        this.chatName = chatName;
    }

    public String getChatName()
    {
        return chatName;
    }

    public void sendMessage(User user1, User user2, String message)
    {
        date = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
        Message newMessage = new Message(user1, user2, message, date);
        this.message[amountMessages++] = newMessage;
    }

    public int getAmountMessages()
    {
        return amountMessages;
    }
    
    public void sendServerMessage(User sender, String message)
    {
        date = Integer.toString(dateToday.get(Calendar.DAY_OF_MONTH))+"/"+Integer.toString(dateToday.get(Calendar.MONTH)+1)+"/"+Integer.toString(dateToday.get(Calendar.YEAR));
        //System.out.printf("[%s] %s (%s) | %s: %s\n", date, s.getName(), this.getChatName(), user1.getName(), message);
        Message newMessage = new Message(sender, message, date);
        this.message[amountMessages++] = newMessage;
    }

    public Message[] getLastMessages()
    {
        return message;
    }

    public String getDate()
    {
        return date;
    }

    public User getUser1()
    {
        return user1;
    }

    public User getUser2()
    {
        return user2;
    }

    public User findUser(String name)
    {
        User user = null;

        if (user1.getUser().equalsIgnoreCase(name))
            user = user1;
        else if (user2.getUser().equalsIgnoreCase(name))
            user = user2;

        return user;
    }
}
