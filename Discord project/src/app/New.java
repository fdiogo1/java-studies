package app;

public abstract class New 
{
    private String name;
    private String image;
    private String dtCreated;

    public New (String name, String image, String dtCreated)
    {
        this.name = name;
        this.image = image;
        this.dtCreated = dtCreated;
    }

    public String getName()
    {
        return name;
    }

    public String getImageLink()
    {
        return image;
    }

    public void setName(String newName)
    {
        name = newName;
    }

    public void setImage(String newImage)
    {
        image = newImage;
    }

    public String getDtCreated()
    {
        return dtCreated;
    }
}
