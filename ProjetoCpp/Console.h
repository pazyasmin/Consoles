#include <string>
#include <ostream>

using std::string;
using std::ostream;

class Console : public Device
{                                                           
    friend ostream &operator<<(ostream &, const Console &);
    
    public:
        Console();
        Console(const Console &);
        Console (const int &, const int &, const int &);
        ~Console();
        bool getInternet();
        void setInternet (bool);
        void insertController(const Controller &, unsigned short int);
        void removeController(unsigned short int);
        void installGame(const Game &);                    
        void uninstallGame();                   
        void createUser(const User &);                      
        void deleteUser();
        void refreshUsedSpace(float); 
        void refreshFreeSpace(); 
        void refreshTotalSpace();
        int findGame(string, int);
        int findUser(string, int);
        void displayGames() const;                          
        void displayUsers() const; 
        void consoleInfo() const;                           
        void update();                                 
        void play(string); 
        
        const Console &operator=(const Console &);              
	    bool operator==(const Console &) const; 
        
        virtual void start() = 0; 
    
    protected:
        string platform;                                        //Plataforma do console 
        float softwareVersion;                                  //Versão de software do sistema
        Date releaseDate;                                       //Data de lançamento
        Date lastUpdated;                                       //Data da última atualização
        float storage[3];                                       //storage[0] = espaço total| storage[1] = espaço usado | storage[2] = espaço livre
        bool internetConnection;                                //Conexão à internet
        Game* games;                                            //Lista de jogos instalados
        User* users;                                            //Lista de usuários
        int nGames;                                             //Nº de jogos
        int nUsers;                                             //Nº de usuários
        const static unsigned short int CONTROLLER_SLOTS = 4;   //Nº máximo de entrada para controles (generalizei para 4 entradas)
        Controller controllers[CONTROLLER_SLOTS];               //Vetor de controles     
};
#endif // CONSOLE_H
