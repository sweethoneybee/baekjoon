#include <iostream>
#include <string>
#include <vector>

class Character
{
public:
    Character() = delete;
    Character(std::string className, std::string characterName) 
    : m_className(className), m_characterName(characterName)
    {
        initializeCharacter();
    }
    virtual ~Character(){}
    void useSkill() const
    {
        
        int skillsNumber = skills.size();
        int select = 0;
        while(select < 1 || select > skillsNumber)
        {
            std::cout << "Select skill to use" << std::endl;
            std::cout << "input -1 to cancel" << std::endl;
            showSkills();
            std::cin >> select;

            if(select == -1)
            {
                std::cout << "You've canceled using skills" << std::endl;
                return;
            }
        }

        std::cout << "You've choosed \"" << skills[select-1] << "\"!" << std::endl;
        showUsingSkill(select - 1);
    }
    void showCharacterInfo() const
    {
        std::cout << "Character name : " << m_characterName << std::endl;
        std::cout << "Class name : " << m_className << std::endl;
    }
    void showStatus() const
    {
        std::cout << "hp : " << status_hp << std::endl;
        std::cout << "mp : " << status_mp << std::endl;
        std::cout << "power : " << status_power << std::endl;
    }
    void showItems() const
    {
        if(items.empty() == true)
        {
            std::cout << "You have no item!" << std::endl;
            return;
        }

        std::cout << "----items----" << std::endl;
        int itemIndex = 1;
        for(auto &item : items)
        {
            std::cout << itemIndex << ". " << item << std::endl;
            ++itemIndex;
        }
        std::cout << "-------------" << std::endl << std::endl;
    }
    void showSkills() const
    {
        if(skills.empty() == true)
        {
            std::cout << "You have no skill!" << std::endl;
            return;
        }

        std::cout << "----skills----" << std::endl;
        int skillIndex = 1;
        for(auto &skill : skills)
        {
            std::cout << skillIndex << ". " << skill << std::endl;
            ++skillIndex;
        }
        std::cout << "-------------" << std::endl << std::endl;
    }

    void setItem(const std::string &itemName)
    {
        if(itemName.compare("") == true)
        {
            std::cout << "invalid item name" << std::endl;
            return;
        }
        items.push_back(itemName);
    }

    void setSkill(const std::string &skillName)
    {
        if(skillName.compare("") == true)
        {
            std::cout << "invalid skill name" << std::endl;
            return;
        }
        skills.push_back(skillName);
    }

protected:
    void initializeCharacter()
    {
        initializeStatus();
        initializeItems();
        initializeSkills();
    }
    virtual void initializeStatus() = 0;
    virtual void initializeItems() = 0;
    virtual void initializeSkills() = 0;
    
    int status_hp = 10;
    int status_mp = 10;
    int status_power = 10;
    int status_agility = 10;
    
private:
    void showUsingSkill(const int index) const
    {
        std::cout << skills[index] << "!!!!" << std::endl;
    }

    const std::string m_className = "none";
    const std::string m_characterName = "noname";  
    std::vector<std::string> items;
    std::vector<std::string> skills;
};

class Warrior : public Character
{
public:
    Warrior() = delete;
    explicit Warrior(const std::string characterName) : Character("Warrior", characterName)
    {
        initializeCharacter();
    }
    ~Warrior(){};


protected:
    void initializeStatus()
    {
        int hp = 50;
        int mp = 20;
        int power = 40;
        int agility = 20;

        this->status_hp = hp;
        this->status_mp = mp;
        this->status_power = power;
        this->status_agility = agility;
    }
    void initializeItems()
    {
        setItem("Long sword");
        setItem("Shield");
        setItem("Boots");
    }
    void initializeSkills()
    {
        setSkill("Wheel Wind");
        setSkill("Power Slay");
        setSkill("Shield Slam");
    }
private:
    
};

class Thief : public Character
{
public:
    Thief() = delete;
    explicit Thief(const std::string characterName) : Character("Thief", characterName)
    {
        initializeCharacter();
    }
    virtual ~Thief(){}

protected: 
    virtual void initializeStatus()
    {
        int hp = 40;
        int mp = 30;
        int power = 30;
        int agility = 30;

        this->status_hp = hp;
        this->status_mp = mp;
        this->status_power = power;
        this->status_agility = agility;
    }
    virtual void initializeItems()
    {
        setItem("Short sword");
        setItem("Long sleeve");
        setItem("Poison potion");
    }
    virtual void initializeSkills()
    {
        setSkill("Steel");
        setSkill("Snapping");
        setSkill("Run away");
    }
private:
};

void temp(Thief a)
{
    a.showCharacterInfo();
}
int main(void)
{
    // string a = "wow";
    // temp(a);
    // Warrior jeong("jeong");
    // jeong.showCharacterInfo();
    // jeong.showStatus();
    // jeong.showItems();
    // jeong.useSkill();
    
    // Thief kim("kim");
    // kim.showCharacterInfo();
    // kim.showStatus();
    // kim.showItems();
    // kim.useSkill();

    system("pause");
    return 0;
}