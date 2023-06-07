
#include    "SPECIFIC_ANNIV.h"
#include    "DMX_2_MIDI.h"
#include <cstdint>

void    ANNIV_mode_strobe(uint8_t gpe){
    uint16_t    add;
    uint16_t    val;
    uint8_t     gp;

    for(int k = 0; k < NB_SPOTS; k++){
        gp = spots[k].getGroup();
        if((gp == gpe) || (gpe == 0)){
            add = spots[k].getAdd()-1;
            switch(type_spot[k][0]){
                case 1: /* Hybrid */
                    val = 1 + ((global_strobe_speed * 254.0) / 255.0);
                    dmx_data[add + 6 - 1] = val;
                    dmx_data[add + 7 - 1] = 0;
                    break;            
                case 2: /* Renkforce */
                    break;          
                case 3: /* SLS-7 */
                    val = 10 + ((global_strobe_speed * 245.0) / 255.0);
                    dmx_data[add + 2 - 1] = val;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 0;
                    break;          
                case 4: /* TMH-46 */
                    val = 10 + ((global_strobe_speed * 239.0) / 255.0);
                    dmx_data[add + 5 - 1] = val;
                    dmx_data[add + 12 - 1] = 0;
                    dmx_data[add + 14 - 1] = 0;
                    break;
                case 5: /* BAR-3 */
                    val = 1 + ((global_strobe_speed * 254.0) / 255.0);
                    dmx_data[add + 2 - 1] = val;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 0;
                    break;
                default:
                    break;
            }
        }
    }
}

void    ANNIV_mode_nofunc(uint8_t gpe){
    uint16_t    add;
    uint16_t    val;
    uint8_t     gp;

    for(int k = 0; k < NB_SPOTS; k++){
                gp = spots[k].getGroup();
        if((gp == gpe) || (gpe == 0)){
            add = spots[k].getAdd()-1;
            switch(type_spot[k][0]){
                case 1: /* Hybrid */
                    dmx_data[add + 6 - 1] = 0;  
                    dmx_data[add + 7 - 1] = 0;  
                    break;            
                case 2: /* RenkForce */
                    break;          
                case 3: /* SLS-7 */
                    dmx_data[add + 2 - 1] = 0;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 0;
                    break;          
                case 4: /* TMH-46 */
                    dmx_data[add + 5 - 1] = 0;
                    dmx_data[add + 12 - 1] = 0;
                    dmx_data[add + 14 - 1] = 0;
                    break;
                case 5: /* BAR-3 */
                    dmx_data[add + 2 - 1] = 0;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 0;
                    break;
                default:
                    break;
            }
        }
    } 
}

void    ANNIV_mode_sound(uint8_t gpe){
    uint16_t    add;
    uint16_t    val;
    uint8_t     gp;

    for(int k = 0; k < NB_SPOTS; k++){
        gp = spots[k].getGroup();
        if((gp == gpe) || (gpe == 0)){
            add = spots[k].getAdd()-1;
            switch(type_spot[k][0]){
                case 1: /* Hybrid */
                    dmx_data[add + 6 - 1] = 0;  
                    dmx_data[add + 7 - 1] = 210;  
                    break;            
                case 2: /* RenkForce */
                    break;          
                case 3: /* SLS-7 */
                    dmx_data[add + 2 - 1] = 0;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 130;
                    break;          
                case 4: /* TMH-46 */
                    dmx_data[add + 5 - 1] = 0;
                    dmx_data[add + 12 - 1] = 158;
                    dmx_data[add + 13 - 1] = 255-global_strobe_speed;
                    dmx_data[add + 14 - 1] = 170;
                    dmx_data[add + 15 - 1] = global_strobe_speed;
                    break;
                case 5: /* BAR-3 */
                    dmx_data[add + 2 - 1] = 0;
                    dmx_data[add + 9 - 1] = 0;
                    dmx_data[add + 10 - 1] = 130;
                    break;
                default:
                    break;
            }
        }
    }
}

