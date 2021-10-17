//
// Created by 刘储宁 on 5/6/21.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
    for (int i = 0; i < LISTS.size(); i++) {
        //j [0,4)
        Menu menu = Menu(LISTS[i]);
        menus.push_back(menu);
        menus[i].setHidden(true);
    }
    mouseHoverinx = -1;
    mouseHoveriny = -1;
    setPosition(MENUBARPOSITIONX, NENUBARPOSITIONY);
    cout << "MenyBar Constructor end" << endl;


}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for (int i = 0; i < menus.size(); i++) {
        window.draw(menus[i], states);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    bool checkmousein = false;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int foundi = -1;
            int foundj = -1;
            bool inMenu = false;
            for (int i = 0; i < menus.size(); i++) {
                for (int j = 0; j < menus[i].getItemList().getItemList().size(); j++) {
                    Item item = *(menus[i].getItemList().getItem(j));
                    inMenu = MouseEvents<Item>::mouseClicked(item, window, event);
                    if (inMenu) {
                        foundi = i;
                        foundj = j;
                        break;
                    }

                }
                if (inMenu) {
                    break;
                }
            }
            cout << "found i = " << foundi << endl;
            cout << "found j = " << foundj << endl;
            if (foundj > 0 && !menus[foundi].getItemList().getItem(foundj)->getHiddenState()) {
                menus[foundi].swithcHiddenState();
                if(foundi == 0&& foundj == 1){
                    window.close();
                }
                if(foundi == 0 && foundj == 2){
                    sf::RenderWindow newWindow(sf::VideoMode(1500,1000),"File") ;
                    save.setInButton(false);
                    notsave.setInButton(false);

                    save.setString("Save");
                    notsave.setString("CANCEL");
                    save.setPosition(sf::Vector2f(550,850));
                    notsave.setPosition(sf::Vector2f(300,850));
                    filename.setTextInputPosition(sf::Vector2f(100,50));
                    while(newWindow.isOpen()){
//                        sf::Event event1;
                        //bool infilename = MouseEvents<FileTree>::mouseClicked(fileTree,newWindow,event);

                        while (newWindow.pollEvent(event))
                        {
                            if ((event.type == sf::Event::Closed))
                            {
                                newWindow.close();
                            }
                            //fileTree.addEventHandler(newWindow,event);
                            filename.addEventHandler(newWindow,event);
                            save.addEventHandler(newWindow,event);

                            if(save.getInButton() == true){
                                CreatTxtFile(filename.getTextInputString());
                                //cout<<"createTxtFile"<<filename.getTextInputString()<<endl;
                                newWindow.close();
                                save.setInButton(false);
                            }

                            notsave.addEventHandler(newWindow,event);
                            if(notsave.getInButton() == true){
                                newWindow.close();
                                notsave.setInButton(false);
                            }
                        }

//                        if(event1.type == sf::Event::Closed) {
//                            break;
//                        }
                        newWindow.clear();
                        filename.textInMemubarupdate(cursor);
                        newWindow.draw(save);
                        newWindow.draw(notsave);
                        newWindow.draw(filename);
                        newWindow.display();
                    }

                    //CreatTxtFile("newfile.txt");
                    //createtxtfile("textfile.txt");
                }
                if(foundi == 0 && foundj == 3){
                    sf::RenderWindow newWindow(sf::VideoMode(NEWWINDOWFOROPENFILE_WIDTH,NEWWINDOWFOROPENFILE_HEIGHT),"Filesname") ;
                    open.setInButton(false);
                    cancel.setInButton(false);
                    string path = "../LogoFile/";
                    for(auto& file : std::__fs::filesystem::directory_iterator{ path }){

                        string newpath  = file.path().string();
                        std::string delimiter = "e/";
                        int pos = newpath.find(delimiter);
                        std::string token = newpath.substr(pos+2);
                        readFilename.push_back(token);

                    }
                    for(int i = 0; i< readFilename.size();i++){
                        fileTree.push("Directory",readFilename[i],Image::FILE);
                    }
                    open.setString("OPEN");
                    cancel.setString("CANCEL");
                    open.setPosition(sf::Vector2f(550,850));
                    cancel.setPosition(sf::Vector2f(300,850));

                    while(newWindow.isOpen()){
//                        sf::Event event1;
                        //bool infilename = MouseEvents<FileTree>::mouseClicked(fileTree,newWindow,event);

                        while (newWindow.pollEvent(event))
                        {
                            if ((event.type == sf::Event::Closed))
                            {
                                newWindow.close();
                            }
                            fileTree.addEventHandler(newWindow,event);
                            open.addEventHandler(newWindow,event);
                            if(open.getInButton() == true){
                                //cout<<"filetree getfilename"<<fileTree.getfilename();
                                fromFile = readFile(fileTree.getfilename());

                                  newWindow.close();
                                open.setInButton(false);
                            }

                            cancel.addEventHandler(newWindow,event);
                            if(cancel.getInButton() == true){
                                    newWindow.close();
                                    cancel.setInButton(false);
                            }
                        }

//                        if(event1.type == sf::Event::Closed) {
//                            break;
//                        }
                        newWindow.clear();
                        fileTree.update();
                        newWindow.draw(fileTree);
                        newWindow.draw(open);
                        newWindow.draw(cancel);
                        newWindow.display();
                    }

                }
                if(foundi == 0 && foundj == 4){
                    window.close();
                }
                if(foundi ==0 && foundj == 5){

                    saveFile(toFile);
                    cout<<"Mouse click on save file"<<endl;
                }
                if(foundi ==1&& foundj == 1){
                    takeScreenshoot(window,"../images/newImage.png");
                    menus[foundj].setHidden(true);
                }

            }

            if (foundj == 0) {
                menus[foundi].swithcHiddenState();
            }

        }


    }
    else if (event.type == sf::Event::MouseLeft) {
        checkmousein = false;
        mouseHoverinx = -1;
        mouseHoveriny = -1;
    } else if (event.type == sf::Event::MouseMoved) {

        checkmousein = true;


        for (int i = 0; i < menus.size(); i++) {
            for (int j = 0; j < menus[i].getItemList().getItemList().size(); j++) {
                Item item = *(menus[i].getItemList().getItem(j));
                //bool inMenubar =
                checkmousein = MouseEvents<Item>::mouseHoverOn(item, window);
                if (checkmousein) {
                    mouseHoveriny = j;
                    mouseHoverinx = i;

                    break;
                }
            }
            if (checkmousein) {
                break;
            }
        }
       // cout << "( " << mouseHoverinx << ", " << mouseHoverinx << endl;
        if (mouseHoveriny >= 1) {
            menus[mouseHoverinx].getItemList().getItem(mouseHoveriny)->hoverOnView();
        }
    }
}

void MenuBar::update() {
    for (int i = 0; i < menus.size(); i++) {
        menus[i].update();

    }
    if (mouseHoverinx != -1 && mouseHoveriny >= 1) {
        menus[mouseHoverinx].getItemList().getItem(mouseHoveriny)->hoverOnView();
    }
}

Snapshot &MenuBar::getSnapshot() {

}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

void MenuBar::setPosition(float x, float y) {
    menuBarPosition.x = x;
    menuBarPosition.y = y;
    float tempx = menuBarPosition.x;
    for (int i = 0; i < menus.size(); i++) {
        menus[i].setPosition(tempx, y);
        tempx += menus[i].getobjectGlobalBounds().at(0).width;
    }


}

const vector<Menu> &MenuBar::getMenus() const {
    return menus;
}

void MenuBar::setMenus(const vector<Menu> &menus) {
    MenuBar::menus = menus;
}

const States &MenuBar::getState() const {
    return state;
}

void MenuBar::setState(const States &state) {
    MenuBar::state = state;
}

const sf::Vector2f &MenuBar::getMenuBarPosition() const {
    return menuBarPosition;
}

void MenuBar::setMenuBarPosition(const sf::Vector2f &menuBarPosition) {
    MenuBar::menuBarPosition = menuBarPosition;
}

vector<vector<sf::FloatRect>> MenuBar::getobjectGlobalBounds() const {
    vector<vector<sf::FloatRect>> itemlistvector;
    for (int i = 0; i < menus.size(); i++) {
        itemlistvector.push_back(menus[i].getobjectGlobalBounds());
    }
    return itemlistvector;
}

void MenuBar::takeScreenshoot(const sf::RenderWindow &window, const string &filename) {
    sf::Texture texture;
    sf::Image image;
    texture.create(window.getSize().x,window.getSize().y);
    texture.update(window);
    //displaybox.setSize(sf::Vector2f(2500,800));
    image = texture.copyToImage();
    //image.flipVertically();
    if (image.saveToFile(filename))
    {
        std::cout << "screenshot saved to " << filename << std::endl;
    }

    if(!image.loadFromFile(filename)){
        cout<<"fail to load file"<<filename<<endl;
        return;
    }

 sf::Image newScreenShot;

    newScreenShot.create(2500,880,sf::Color::Red);
    newScreenShot.copy(image,0,0);
    newScreenShot.flipVertically();
    //newScreenShot.loadFromMemory(image.getPixelsPtr(),128);
    //texture.loadFromImage(newScreenShot,sf::IntRect(10,10,10,10));

    sf::Color pixelcolot = getPixelColor();
//    for(int i = 0 ;i < MENUBARINPUTBOX_WIDTH*9;i++){
//        for(int j = 0;j < MENUBERINPUTBOX_HEIGHT*2;j++){
//            newScreenShot.setPixel(i,j,pixelcolot);
//        }
//    }


    if(!newScreenShot.saveToFile(filename)){
        cout<<"file to save to file "<<endl;
        return;
    }
    sf::Image newnewScreenShot;
    newnewScreenShot.create(2500,740,sf::Color::Red);
    newnewScreenShot.copy(newScreenShot,0,0);
    newnewScreenShot.flipVertically();
    if(!newnewScreenShot.saveToFile(filename)){
        cout<<"file to save to file "<<endl;
        return;
    }
}

string MenuBar::readFile(string filename) {
    ifstream readfile;
    readfile.open("../LogoFile/"+filename);
    if(readfile.fail()){
        cout<<"file opening failed"<<endl;
        exit(1);
    }
    string logoText;
    getline(readfile,logoText);
    while (!readfile.eof()){
         getline(readfile,logoText);
    }
    readfile.close();
    return logoText;
}

string MenuBar::getString() {
    return fromFile;
}

void MenuBar::setString(string s) {
    this->fromFile = s;
}

void MenuBar::saveFile(string textinput) {

    std::ofstream saveFile;
    saveFile.open("../LogoFile/"+newfilename+".txt");
    if(saveFile.fail()){
        cout<<"save file is fail"<<endl;
        exit(1);
    }
    saveFile<<textinput;
    saveFile.close();

}

void MenuBar::settoFileString(string filetext) {
    toFile = filetext;
    //cout<<"settoFIleStirng"<<toFile<<endl;
}

string MenuBar::gettoFileStirng() {
    return toFile;
}

string MenuBar::CreatTxtFile(string txtfileName) {
    std::ofstream saveFile;
    newfilename = txtfileName;
    saveFile.open("../LogoFile/"+txtfileName+".txt");
    saveFile.close();
    return  newfilename;
}

void MenuBar::createtxtfile(string filename) {
    std::ofstream saveFile;
    saveFile.open("../LogoFile/"+filename);
    saveFile.close();
}

void MenuBar::setPixelColor(sf::Color pixelcolor) {
       pixelcolor = color;
}

sf::Color& MenuBar::getPixelColor() {
    return color;
}

