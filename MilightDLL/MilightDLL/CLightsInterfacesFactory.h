#ifndef CLIGHTSINTERFACESFACTORY_H
#define CLIGHTSINTERFACESFACTORY_H

#include "ILEDInterface.h"
#include <memory>

namespace smartLights
{
namespace smartLightsBackend
{
    class CLightsInterfacesFactory
    {
    public:
        ///////////////////////////////////
        /// \brief CLightsInterfacesFactory
        ///
        CLightsInterfacesFactory();

        ///////////////////////////////////
        /// \brief getInterface
        /// \param a_eInterface
        /// \return
        ///
        static std::unique_ptr<ILEDInterface> getInterface(ILEDInterface::eInterfaces a_eInterface);
    };
}
}
#endif // CLIGHTSINTERFACESFACTORY_H
