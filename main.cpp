#include <QGuiApplication>
#include <QQmlApplicationEngine>

/*
 What
 State machine in QML

 Description
 Yes...its in QML

 Why
 Because QML has state built right into it

 Example
 Basic state example in QML
 https://doc.qt.io/qt-5/qmlstatemachine.html

 */


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
