/*H**********************************************************************
* FILENAME :        M2D_FILES.cpp             
*
* DESCRIPTION :
*       File access on SD card routines.
*
* NOTES :
*       These functions are a part of the MIDI2DMX application
*       Developped by Villou / LEnsE
**
* AUTHOR :    Julien VILLEMEJANE        START DATE :    22/sept/2022
*
*       LEnsE / Institut d'Optique Graduate School
*H***********************************************************************/

#include    "M2D_LENSE.h"

/* Inputs / Outputs */
SDBlockDevice       sd_card(PE_6, PE_5, PE_2, PE_3, 1000000, 0);
    //PinName 	mosi = NC, PinName 	miso = NC, PinName 	sclk = NC,
    //PinName 	cs = NC, uint64_t 	hz = 1000000, bool 	crc_on = 0 
FATFileSystem       file_syst("fs");

/* Global Variables */


/* Mount SD Card */
void    mountSDcard(void){
    LCD_DOG_clear_Line(3);
    LCD_DOG_writeStr((char *)"Mounting...", 3, 1);
    int err = file_syst.mount(&sd_card);
    if(DEBUG)   if(err)     LCD_DOG_writeStr((char *)"ERR", 3, 12);
}

/* Unmount SD Card */
void    unmountSDcard(void){
    LCD_DOG_clear_Line(3);
    LCD_DOG_writeStr((char *)"UnMounting...", 3, 1);
    int err = file_syst.unmount();
    if(DEBUG)   if(err)     LCD_DOG_writeStr((char *)"ERR", 3, 12);
}

/* update the setup of the address list of spots - *.adr file */
void    openNewAddress(char* fileName) {
    char    filedir[20];
    char    temp_char;
    char    temp_string_[17];
    int     err;
    strcpy(filedir,"/fs/");
    strcat(filedir,fileName);
    strcat(filedir,".adr");

    sprintf(temp_string_, "%s", filedir);
    LCD_DOG_writeStr(temp_string_, 3, 1);
    // Mounting file system
    mountSDcard();
    // Open the file
    LCD_DOG_writeStr((char*)"Opening...", 2, 1);  
    FILE*   f = fopen(filedir, "r+");
    if(DEBUG){ 
        LCD_DOG_clear_Line(3);
        if(!f) LCD_DOG_writeStr((char*)"Open_Fail :(", 3, 1);    
    }  

    // if file ok : 
    if(f){
        int         setup_number;
        char        setup_name[17];
        char        setup_type;
        int         spot_number, spot_addr, spot_chan, spot_gpe, spot_mode, spot_nofunc;
        int         spot_dim, spot_dim_min, spot_dim_max, spot_r, spot_g, spot_b;
        int         spot_w, spot_a, spot_uv;
        char        spot_mode_type;
        // Read header line [ADRxxx] nom_preconfig
        fscanf(f, "[ADR%d] %s\n", &setup_number, setup_name);
        sprintf(temp_string_, "%s", setup_name);
        LCD_DOG_clear_Line(3);
        LCD_DOG_writeStr(temp_string_, 3, 1); 

        while (!feof(f)){
            // Read data line 
            fscanf(f, "%c", &setup_type);
            switch(setup_type){
                case '#':       // Comments line
                    do{
                        fscanf(f, "%c", &temp_char);
                    }while(temp_char != '#');
                    fscanf(f, "\n");
                    break;
                case 'S':       // new spot configuration
                    // S[nn]adr:nbr:gpe:mode:nofunc:dim:dim_min:dim_max:r:g:b:w:a:uv: 
                    if(DEBUG){   
                        sprintf(temp_string_, "New Spot Setup");
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    fscanf(f, "[%d]", &spot_number);
                    if(DEBUG){   
                        sprintf(temp_string_, "Spot Number : %d", spot_number);
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    fscanf(f, "%d:", &spot_addr);                    
                    if(DEBUG){   
                        sprintf(temp_string_, "Spot Addr : %d", spot_addr);
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    fscanf(f, "%d:", &spot_chan);                   
                    if(DEBUG){   
                        sprintf(temp_string_, "Chan Count : %d", spot_chan);
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    fscanf(f, "%d:", &spot_gpe);               
                    if(DEBUG){   
                        sprintf(temp_string_, "Spot Group : %d", spot_gpe);
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    /* Adding a new spot to the list */
                    if(global_spots_number < spot_number){
                        global_spots_number++;
                        spots_list[global_spots_number-1].setAdd(spot_addr);
                        spots_list[global_spots_number-1].setChan(spot_chan);
                        spots_list[global_spots_number-1].setGroup(spot_gpe);
                    }
                    fscanf(f, "%d:", &spot_mode);        
                    if(DEBUG){   
                        sprintf(temp_string_, "SpotModeCh: %2d", spot_mode);
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    } 
                    fscanf(f, "%d:", &spot_nofunc);
                    spots_list[global_spots_number-1].setChanNoFuncMode(spot_mode, spot_nofunc);
                    /* Dimmer */
                    fscanf(f, "%d:", &spot_dim);
                    spots_list[global_spots_number-1].setChanDimmer(spot_dim);
                    fscanf(f, "%d:", &spot_dim_min);
                    spots_list[global_spots_number-1].setDimmerMin(spot_dim_min);
                    fscanf(f, "%d:", (int*)&spot_dim_max); 
                    spots_list[global_spots_number-1].setDimmerMax(spot_dim_max);
                    /* RGBWAUV */
                    fscanf(f, "%d:", (int*)&spot_r);
                    fscanf(f, "%d:", (int*)&spot_g);
                    fscanf(f, "%d:", (int*)&spot_b);  
                    spots_list[global_spots_number-1].setChanRGB(spot_r, spot_g, spot_b);  
                    fscanf(f, "%d:", (int*)&spot_w);
                    spots_list[global_spots_number-1].setChanW(spot_w);
                    fscanf(f, "%d:", (int*)&spot_a);
                    spots_list[global_spots_number-1].setChanA(spot_a);
                    fscanf(f, "%d:\n", (int*)&spot_uv);  
                    spots_list[global_spots_number-1].setChanUV(spot_uv);
                    break;
                case 'M':       // new mode configuration
                    // M[nn]P:pan:pan_f:
                    if(DEBUG){   
                        sprintf(temp_string_, "New Mode Setup");
                        LCD_DOG_writeStr(temp_string_, 3, 1);
                    }
                    fscanf(f, "[%d]", &spot_number);
                    fscanf(f, "%c:", &spot_mode_type);
                    if(global_spots_number >= spot_number){
                        switch(spot_mode_type){
                            case 'P':   // M[nn]P:pan:pan_f:
                                if(DEBUG){   
                                    sprintf(temp_string_, "Pan Mode");
                                    LCD_DOG_writeStr(temp_string_, 3, 1); 
                                }
                                break;
                                // Add options
                            case 'T':   // M[nn]T:tilt:tilt_f: 
                                if(DEBUG){   
                                    sprintf(temp_string_, "Tilt Mode");
                                    LCD_DOG_writeStr(temp_string_, 3, 1); 
                                }
                                break;
                                // Add options
                            case 'S':   // M[nn]S:strobe:strobe_mode_v:inde:strobe_speed:strobe_min:strobe_max: 
                                int spot_ch_strobe_mode, spot_strobe_mode, strobe_inde;
                                int spot_ch_speed, spot_strobe_min, spot_strobe_max;
                                if(DEBUG){   
                                    sprintf(temp_string_, "Strobe Mode");
                                    LCD_DOG_writeStr(temp_string_, 3, 1); 
                                }
                                fscanf(f, "%d:", &spot_ch_strobe_mode);
                                fscanf(f, "%d:", &spot_strobe_mode);
                                fscanf(f, "%d:", &strobe_inde);
                                spots_list[global_spots_number-1].setChanStrobe(spot_ch_strobe_mode, strobe_inde, spot_strobe_mode);
                                fscanf(f, "%d:", &spot_ch_speed);
                                spots_list[global_spots_number-1].setChanStrobeSpeed(spot_ch_speed);
                                fscanf(f, "%d:", &spot_strobe_min);
                                spots_list[global_spots_number-1].setStrobeSpeedMin(spot_strobe_min);
                                fscanf(f, "%d:\n", &spot_strobe_max);
                                spots_list[global_spots_number-1].setStrobeSpeedMax(spot_strobe_max);
                                break;
                            case 'D':   // M[nn]D:inde:sound:sound_min:sound_max: 
                                int sound_inde, spot_ch_sound, spot_sound_min, spot_sound_max;
                                if(DEBUG){   
                                    sprintf(temp_string_, "Sound Mode");                                
                                    LCD_DOG_writeStr(temp_string_, 3, 1); 
                                }
                                fscanf(f, "%d:", &sound_inde);
                                fscanf(f, "%d:", &spot_ch_sound);
                                fscanf(f, "%d:", &spot_sound_min);
                                fscanf(f, "%d:\n", &spot_sound_max);
                                spots_list[global_spots_number-1].setChanSoundMode(spot_ch_sound, sound_inde, spot_sound_min, spot_sound_max);
                                break;
                            default:
                                if(DEBUG){   
                                    sprintf(temp_string_, "No Mode");
                                    LCD_DOG_writeStr(temp_string_, 3, 1); 
                                }
                        }    
                    }                
                    break;
                default:                            
                    if(DEBUG){   
                        sprintf(temp_string_, "Setup Type Error");
                        LCD_DOG_writeStr(temp_string_, 3, 1); 
                    }
            }
        }

        err = fclose(f);
        if(err != 0){
            if(DEBUG)   {       
                sprintf(temp_string_, "%s", (err ? "Fail :(" : "OK"));
                LCD_DOG_writeStr(temp_string_, 3, 1); 
            }
        }
    }
    
    // Unmounting file system
    unmountSDcard();
}

/*
// update the setup of the notes list - *.not file
void openNewNotes(char* fileName) {
    char    filedir[20];
    strcpy(filedir,"/fs/");
    strcat(filedir,fileName);
    strcat(filedir,".not");
    // Mounting file system
    if(DEBUG)   {       
        sprintf(rec_data, "\r\tMounting...\n");
        this->_pc.write(rec_data, strlen(rec_data));
    }
    int err = this->_fileSystem.mount(&(this->_sd));    
    if(DEBUG)   {       
        sprintf(rec_data, "%s\n", (err ? "Fail :(" : "OK"));
        this->_pc.write(rec_data, strlen(rec_data));
    }

    // Open the file
    if(DEBUG)   {       
        sprintf(rec_data, "Opening \"%s\"... ", filedir);
        this->_pc.write(rec_data, strlen(rec_data));
    }
    fflush(stdout);

    FILE*   f = fopen(filedir, "r+");
    if(DEBUG)   {       
        sprintf(rec_data, "%s\n", (!f ? "Fail :(" : "OK"));
        this->_pc.write(rec_data, strlen(rec_data));
    }

    // if file ok : 
    int         setup_number;
    char        setup_name[17];
    int         note_nbr;
    char        note_type;
    int         note_gpe, note_mode;
    int         tmp, strobe_on, sound_on;
    DMX_values  *temp;
    if(f){
        // Read header line [NOTExxx] nom_preconfig
        fscanf(f, "[NOTE%d] %s\n", &setup_number, setup_name);    
        if(DEBUG)   {       
            sprintf(rec_data, "\rFILE NAME : %s\n", setup_name);
            this->_pc.write(rec_data, strlen(rec_data));
        }
        while (!feof(f)){   // Data lines
        // [nnn]N(gpe)MODE::DIM:...
            fscanf(f, "[%d]%c", &note_nbr, &note_type);
            if(DEBUG)   {       
                sprintf(rec_data, "\r\tNote Type = %c \n", note_type);
                this->_pc.write(rec_data, strlen(rec_data));
            }
            switch(note_type){
                case 'N' :  // real note
                    // [nnn]N(gpe)MODE::DIM:R:G:B:W:A:UV::PAN:PANF:TILT:TILTF:SPEED::STROBE:STSPEED::SOUND::GOBOS1:GOBOS2:GOBOS3:COULEUR:
                    if(DEBUG)   {       
                        sprintf(rec_data, "\rSpecific Note\n");
                        this->_pc.write(rec_data, strlen(rec_data));
                    }                    
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tNote Nbr = %d \n", note_nbr);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    fscanf(f, "(%d)%d::", &note_gpe, &note_mode);
                    if(note_gpe <= MIDI_NB_GROUP)
                        temp = this->_midi_controller->getNoteValues(note_nbr, note_gpe-1);
                    else
                        temp = NULL;
                    temp->setMode(note_mode);
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tMODE = %d\n", note_mode);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    fscanf(f, "%d:", &tmp);
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tD = %d\n", tmp);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    temp->setDimmer(tmp);
                    fscanf(f, "%d:", &tmp);
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tR = %d\n", tmp);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    temp->setR(tmp);
                    fscanf(f, "%d:", &tmp);
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tG = %d\n", tmp);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    temp->setG(tmp);
                    fscanf(f, "%d:", &tmp);
                    if(DEBUG)   {       
                        sprintf(rec_data, "\r\tB = %d\n", tmp);
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    temp->setB(tmp);
                    fscanf(f, "%d:", &tmp);
                    temp->setW(tmp);
                    fscanf(f, "%d:", &tmp);
                    temp->setA(tmp);
                    fscanf(f, "%d::", &tmp);
                    temp->setUV(tmp);   
                    fscanf(f, "%d:", &tmp);  
                    temp->setPan(tmp);    
                    fscanf(f, "%d:", &tmp);  
                    temp->setPanF(tmp);     
                    fscanf(f, "%d:", &tmp);  
                    temp->setTilt(tmp);    
                    fscanf(f, "%d:", &tmp);  
                    temp->setTiltF(tmp);   
                    fscanf(f, "%d::", &tmp);  
                    temp->setPTSpeed(tmp); 
                    fscanf(f, "%d:", &strobe_on);
                    temp->setModeStrobe(strobe_on);
                    fscanf(f, "%d::", &tmp); 
                    temp->setSTSpeed(tmp);   
                    fscanf(f, "%d::", &sound_on);
                    temp->setModeSound(sound_on);  
                    fscanf(f, "%d:", &tmp); // gobos1
                    fscanf(f, "%d:", &tmp); // gobos2    
                    fscanf(f, "%d:", &tmp); // gobos3
                    fscanf(f, "%d:\n", &tmp); // couleurs    
                    break;
                case 'G' :  // global mode
                    if(DEBUG)   {       
                        sprintf(rec_data, "\rGlobal Note\n");
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
                    break;
                default:
                    if(DEBUG)   {       
                        sprintf(rec_data, "\rNote Type Error\n");
                        this->_pc.write(rec_data, strlen(rec_data));
                    } 
            }
        }

        err = fclose(f);
        if(err != 0)
            if(DEBUG)   {       
                sprintf(rec_data, "%s\n", (err < 0 ? "Fail :(" : "OK"));
                this->_pc.write(rec_data, strlen(rec_data));
            }
    }
    
    err = this->_fileSystem.unmount();
    if(DEBUG)   {       
        sprintf(rec_data, "%s\n", (err < 0 ? "Fail :(" : "OK"));
        this->_pc.write(rec_data, strlen(rec_data));
    }
}
*/

/* update the setup of the controls list - *.ctr file */
void    openNewConfig(char* fileName) {
    int         setup_number;
    char        setup_name[17];
    char        temp_string_[17];
    char        filedir[20];
    int         control_nbr;
    char        control_type;
    int         control_tor;
    int         err;
    strcpy(filedir,"/fs/");
    strcat(filedir,fileName);
    strcat(filedir,".ctr");
    // Mounting file system
    mountSDcard();
    // Open the file
    LCD_DOG_clear_Line(3);
    LCD_DOG_writeStr((char*)"Opening...", 3, 1);  
    FILE*   f = fopen(filedir, "r+");
    if(DEBUG){ 
        LCD_DOG_clear_Line(3);
        if(!f) LCD_DOG_writeStr((char*)"Open_Fail :(", 3, 1);    
    }  
    
    if(f){
        // Read header line [CTRLxxx] nom_preconfig
        fscanf(f, "[CTRL%d] %s\n", &setup_number, setup_name);
        sprintf(temp_string_, "%s", setup_name);
        LCD_DOG_clear_Line(3);
        LCD_DOG_writeStr(temp_string_, 3, 1); 

            
        err = fclose(f);
        if(err != 0){
            if(DEBUG)   {       
                sprintf(temp_string_, "%s", (err ? "Fail :(" : "OK"));
                LCD_DOG_writeStr(temp_string_, 3, 1); 
            }
        }
    }
    
    unmountSDcard();

}
    