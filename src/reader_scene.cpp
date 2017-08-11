#include <iostream>
    
    ReaderScene::ReaderScene(std::string file_name){
        
        std::vector<std::string> lexemes = readLexemes(readLines(file_name));
    
        for(unsigned int i =0;i<lexemes.size();i++){
            if(lexemes[i]=="NAME"){
                this->scene.name = lexemes[i+2];
            }else{
                if(lexemes[i]=="TYPE" ){
                    this->scene.type = lexemes[i+2];
                }else{
                    if(lexemes[i]=="CODIFICATION"){
                        this->scene.codification = lexemes[i+2];
                    }else{
                        if(lexemes[i]=="WIDTH"){
                            this->scene.width = std::stoi(lexemes[i+2],nullptr,0);
                        }else{
                            if(lexemes[i]=="HEIGHT"){
                                this->scene.height = std::stoi(lexemes[i+2],nullptr,0);
                            }else{
                                if(lexemes[i]=="UPPER_LEFT"){
                                    this->scene.upper_left[rgb::R] = std::stoi(lexemes[i+2],nullptr,0);
                                    this->scene.upper_left[rgb::G] = std::stoi(lexemes[i+3],nullptr,0);
                                    this->scene.upper_left[rgb::B] = std::stoi(lexemes[i+4],nullptr,0);
                                }else{
                                    if(lexemes[i]=="UPPER_RIGHT"){
                                        this->scene.upper_right[rgb::R] = std::stoi(lexemes[i+2],nullptr,0);
                                        this->scene.upper_right[rgb::G] = std::stoi(lexemes[i+3],nullptr,0);
                                        this->scene.upper_right[rgb::B] = std::stoi(lexemes[i+4],nullptr,0);
                                    }else{
                                        if(lexemes[i]=="LOWER_RIGHT"){
                                            this->scene.lower_right[rgb::R] = std::stoi(lexemes[i+2],nullptr,0);
                                            this->scene.lower_right[rgb:: G] = std::stoi(lexemes[i+3],nullptr,0);
                                            this->scene.lower_right[rgb::B] = std::stoi(lexemes[i+4],nullptr,0);
                                        }else{
                                            if(lexemes[i]=="LOWER_LEFT"){
                                                this->scene.lower_left[rgb::R] = std::stoi(lexemes[i+2],nullptr,0);
                                                this->scene.lower_left[rgb:: G] = std::stoi(lexemes[i+3],nullptr,0);
                                                this->scene.lower_left[rgb::B] = std::stoi(lexemes[i+4],nullptr,0);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
            
    }
        
    Scene& ReaderScene::getScene(){
        return this->scene;
    }