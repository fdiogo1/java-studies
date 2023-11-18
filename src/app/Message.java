package app;

public class Message 
{
    private User sender;
    private User receiver;
    private String message;
    private String date;
    
    public Message (User sender, User receiver, String message, String date) // between two users
    {
        this.sender = sender;
        this.receiver = receiver;
        this.message = message;
        this.date = date;
    }

    public Message (User sender, String message, String date) // for a server
    {
        this.sender = sender;
        this.message = message;
        this.date = date;
        this.receiver = null;
    }

    public String getSender()
    {
        return sender.getName();
    }

    public String getReceiver()
    {
        return receiver.getName();
    }

    public String getMessage()
    {
        return message;
    }

    public String getDate()
    {
        return date;
    }

}
