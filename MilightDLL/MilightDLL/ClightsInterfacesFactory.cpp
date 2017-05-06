#include "CLightsInterfacesFactory.h"

#include "CMilightSource.h"

namespace smartLights
{
namespace smartLightsBackend
{

    CLightsInterfacesFactory::CLightsInterfacesFactory()
    {

    }

    std::unique_ptr<ILEDInterface> CLightsInterfacesFactory::getInterface(ILEDInterface::eInterfaces a_eInterface)
    {
        std::unique_ptr<ILEDInterface> pIface = nullptr;
        switch(a_eInterface)
        {
            case ILEDInterface::E_IF_MILIGTH:
            {
                pIface = std::unique_ptr<ILEDInterface>(new CMilightSource());
            }
            break;

            default:
            {

            }
            break;
        }
        return pIface;
    }

}
}
