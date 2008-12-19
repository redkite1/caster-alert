#include <QApplication>
#include "casteralertlistenerimpl.h"

int main(int argc, char ** argv)
{
    QApplication app( argc, argv );
    // Before instanciating CasterAlertListenerImpl... otherwise it can't work properly
    QApplication::setOrganizationName("CasterInfo");
    QApplication::setOrganizationDomain("casterinfo.be");
    QApplication::setApplicationName("Caster Alert Listener");

    CasterAlertListenerImpl win;

    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );

    return app.exec();
}
