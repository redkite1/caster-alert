#include <QApplication>
#include "casteralertsenderimpl.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );

    QApplication::setOrganizationName("CasterInfo");
    QApplication::setOrganizationDomain("casterinfo.be");
    QApplication::setApplicationName("Caster Alert Sender");
    CasterAlertSenderImpl win;

    win.show();

    return app.exec();
}
