#ifndef CMESSAGECREATOR_H
#define CMESSAGECREATOR_H

#include "CommonTypes.h"
#include <cstdlib>
#include <stdint.h>

class CMessageCreator
{
public:
    /////////////////////////////////
    /// \brief CMessageCreator
    ///
    CMessageCreator()
    {}

    ////////////////////////////////
    /// \brief createNormalMessage
    /// \param a_iValue
    /// \return
    ///
    inline void createNormalMessage(char* a_aiMessage, uint32_t a_iValue)
    {
        a_aiMessage[commonTypes::limitless::E_MESSAGE_START_INDEX] = a_iValue;
        a_aiMessage[commonTypes::limitless::E_MESSAGE_START_INDEX + 1] = 0x00;
        a_aiMessage[commonTypes::limitless::E_MESSAGE_END_INDEX] = commonTypes::limitless::E_MESSAGE_END_BYTE;
    }

    ///////////////////////////////
    /// \brief createSpecialMessage
    /// \param a_iPrefix
    /// \param a_iValue
    /// \return
    ///
    inline void createSpecialMessage(char* a_aiMessage, uint32_t a_iPrefix, uint32_t a_iValue)
    {
        a_aiMessage[commonTypes::limitless::E_MESSAGE_START_INDEX] = a_iPrefix;
        a_aiMessage[commonTypes::limitless::E_MESSAGE_START_INDEX + 1] = a_iValue;
        a_aiMessage[commonTypes::limitless::E_MESSAGE_END_INDEX] = commonTypes::limitless::E_MESSAGE_END_BYTE;
    }

    ////////////////////////////
    /// \brief createMessage
    /// \param a_iValue
    /// \return
    ///
    static void createMessage(char* a_piMessage, uint32_t a_iValue)
    {
        CMessageCreator _oMessageCreator;
        _oMessageCreator.createNormalMessage(a_piMessage, a_iValue);
    }

    ///////////////////////////////
    /// \brief createMessage
    /// \param a_iPrefix
    /// \param a_iValue
    /// \return
    ///
    static void createMessage(char* a_piMessage, uint32_t a_iPrefix, uint32_t a_iValue)
    {
        CMessageCreator _oMessageCreator;
        _oMessageCreator.createSpecialMessage(a_piMessage, a_iPrefix, a_iValue);
    }
};

#endif // CMESSAGECREATOR_H
