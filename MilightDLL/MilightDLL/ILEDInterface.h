#ifndef ICOMMANDSENDERINFERACE
#define ICOMMANDSENDERINFERACE

#include <cstdlib>
#include <stdint.h>

typedef bool bool_t;

//////////////////////////////////////////////////
/// \brief The IcommandSenderInteface class
/// \url http://www.limitlessled.com/dev/

class ILEDInterface
{
public:

    enum eInterfaces
    {
        E_IF_MILIGTH,
    };

    /////////////////////////////////////
    /// \brief The eColors enum
    ///
    enum eColours
    {
        E_COLOUR_MIN = 0x00,
        E_COLOUR_VIOLET = 0x00, // Violet
        E_COLOUR_R_BLUE = 0x10, // Royal_Blue
        E_COLOUR_B_BLUE = 0x20, // Baby_Blue
        E_COLOUR_AQUA   = 0x30, // Aqua
        E_COLOUR_MINT   = 0x40, // Mint
        E_COLOUR_S_GREEN = 0x50, // Seafoam_Green
        E_COLOUR_GREEN  = 0x60, //Green
        E_COLOUR_L_GREEN = 0x70, // Lime_Green
        E_COLOUR_YELLOW = 0x80, //Yellow
        E_COLOUR_Y_ORANGE = 0x90, // Yellow_Orange
        E_COLOUR_ORANGE = 0xA0, // Orange
        E_COLOUR_RED = 0xB0, //Red
        E_COLOUR_PINK = 0xC0, // Pink
        E_COLOUR_FUSIA = 0xD0, // Fusia
        E_COLOUR_LILAC = 0xE0, // Lilac
        E_COLOUR_LAVENDAR = 0xF0, // Lavendar
        E_COLOUR_MAX = 0xFF,
    };

    ////////////////////////////////////
    /// \brief The eGroup enum
    ///
    enum eGroup
    {
        E_GROUP_ALL = 0,
        E_GROUP_1 = 1,
        E_GROUP_2 = 2,
        E_GROUP_3 = 3,
        E_GROUP_4 = 4,
        E_GROUP_MAX = 4
    };

    /////////////////////////////////////
    /// \brief The eBrightness enum
    ///
    enum eBrightness
    {
        E_BRIGHTNESS_MIN = 0,
        E_BRIGHTNESS_MAX = 100
    };

    //////////////////////////////////
    /// \brief sendTurnOnReq
    /// \param a_eGroup
    /// \return
    ///
    virtual bool_t sendTurnOnReq(eGroup a_eGroup) = 0;

    /////////////////////////////////
    /// \brief sendTurnOffReq
    /// \param a_eGroup
    /// \return
    ///
    virtual bool_t sendTurnOffReq(eGroup a_eGroup) = 0;

    /////////////////////////////////
    /// \brief sendWhiteReq
    /// \param a_eGroup
    /// \return
    ///
    virtual bool_t sendWhiteReq(eGroup a_eGroup) = 0;

    /////////////////////////////////
    /// \brief sendBrightnessReq
    /// \param a_eGroup
    /// \param a_uiProc
    /// \return
    ///
    virtual bool_t sendBrightnessReq(eGroup a_eGroup, int16_t a_uiProc = 100) = 0;

    ////////////////////////////////
    /// \brief sendColourReq
    /// \param a_eGroup
    /// \param a_eColour
    /// \return
    ///
    virtual bool_t sendColourReq(eGroup a_eGroup, eColours a_eColour) = 0;

    ////////////////////////////////
    /// \brief sendColourReq
    /// \param a_eGroup
    /// \param a_uiColour
    /// \return
    ///
    virtual bool_t sendColourReq(eGroup a_eGroup, int16_t a_uiColour) = 0;

    /////////////////////////////
    /// \brief ~IcommandSenderInteface
    ///
    virtual ~ILEDInterface(){};
};

#endif // ICOMMANDSENDERINFERACE

