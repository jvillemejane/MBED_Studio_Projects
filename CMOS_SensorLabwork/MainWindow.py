# Libraries to import
import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QGridLayout, QWidget, QPushButton, QAction
from PyQt5.QtGui import QIcon

from NewCameraWidget import Camera_Widget
from ChartWidget import Chart_Widget
from SensorSettingsWidget import Sensor_Settings_Widget
from SettingsWidget import Settings_Widget
from HistogramWidget import Histogram_Widget

#-------------------------------------------------------------------------------------------------------

# Colors
"""
Colors :    Green  : #c5e0b4
            Blue   : #4472c4
             Light : #7fadff
            Orange : #c55a11
             Light : #ff8d3f
            Beige  : #fff2cc
            Grey1  : #f2f2f2
            Grey2  : #bfbfbf
"""

#-------------------------------------------------------------------------------------------------------


class MainWidget(QWidget):
    """
    Main Widget of our Main Window.

    Args:
        QWidget (class): QWidget can be put in another widget and / or window.
    """
    def __init__(self):
        """
        Initialisation of the main Widget.
        """
        super().__init__()
        self.setStyleSheet("background: #f2f2f2;")

        # Choosing the optimate value for the measurement
        self.measurementInterval = 300

        # Tested values
        # 100  => 1.35s      |      325  => 1s
        # 250  => 1.25s      |      400  => 1.22s
        # 275  => 1.22s  ok  |      500  => 1.5s
        # 300  => 0.95s      |      1000 => 2s  

        # Create the several widgets
        self.cameraWidget = Camera_Widget()
        self.chartWidget = Chart_Widget(measurementInterval = self.measurementInterval)
        self.settingsWidget = Settings_Widget()
        self.cameraHistogramWidget = Histogram_Widget(histogramTitle = "Camera's histogram", FrameOrLists =  "frame", measurementInterval = self.measurementInterval)
        self.chartHistogramWidget = Histogram_Widget(histogramTitle = "Pixels' histogram", FrameOrLists ="lists", measurementInterval = self.measurementInterval)
        self.sensorSettingsWidget = Sensor_Settings_Widget()

        # Create and add the widgets into the layout
        layoutMain = QGridLayout()
        self.setLayout(layoutMain)

        layoutMain.addWidget(self.cameraWidget, 0, 0, 4, 4) # row = 0, column = 0, rowSpan = 4, columnSpan = 4
        layoutMain.addWidget(self.sensorSettingsWidget, 4, 0, 4, 4) # row = 4, column = 0, rowSpan = 4, columnSpan = 4
        layoutMain.addWidget(self.chartWidget, 0, 5, 4, 4) # row = 0, column = 5, rowSpan = 4, columnSpan = 4
        layoutMain.addWidget(self.cameraHistogramWidget, 4, 5, 4, 2) # row = 4, column = 5, rowSpan = 4, columnSpan = 2
        layoutMain.addWidget(self.chartHistogramWidget, 4, 7, 4, 2) # row = 4, column = 7, rowSpan = 4, columnSpan = 2

        
        self.cameraWidget.connectCamera()
        self.cameraWidget.launchVideo()

        self.initSettings()

        # lambda function used to prevent the Nonetype error        
        self.settingsWidget.AOISettingX.slider.valueChanged.connect(lambda : self.cameraWidget.launchAOI(
                                                            self.settingsWidget.AOIXGetValue(),
                                                            self.settingsWidget.AOIYGetValue(),
                                                            self.settingsWidget.AOIWidthGetValue(),
                                                            self.settingsWidget.AOIHeightGetValue(),
                                                            type = "forced"))
        
        self.settingsWidget.AOISettingY.slider.valueChanged.connect(lambda : self.cameraWidget.launchAOI(
                                                            self.settingsWidget.AOIXGetValue(),
                                                            self.settingsWidget.AOIYGetValue(),
                                                            self.settingsWidget.AOIWidthGetValue(),
                                                            self.settingsWidget.AOIHeightGetValue(),
                                                            type = "forced"))
        
        self.settingsWidget.AOISettingWidth.slider.valueChanged.connect(lambda : self.cameraWidget.launchAOI(
                                                            self.settingsWidget.AOIXGetValue(),
                                                            self.settingsWidget.AOIYGetValue(),
                                                            self.settingsWidget.AOIWidthGetValue(),
                                                            self.settingsWidget.AOIHeightGetValue(),
                                                            type = "forced"))
        
        self.settingsWidget.AOISettingHeight.slider.valueChanged.connect(lambda : self.cameraWidget.launchAOI(
                                                            self.settingsWidget.AOIXGetValue(),
                                                            self.settingsWidget.AOIYGetValue(),
                                                            self.settingsWidget.AOIWidthGetValue(),
                                                            self.settingsWidget.AOIHeightGetValue(),
                                                            type = "forced"))

    def initSettings(self):
        """
        Method used to setup the settings.
        """
        # Initialisation of the AOI settings
        self.settingsWidget.AOISettingX.slider.setMaximum(self.cameraWidget.max_width)
        self.settingsWidget.AOISettingX.slider.setValue(self.cameraWidget.max_width//4)

        self.settingsWidget.AOISettingY.slider.setMaximum(self.cameraWidget.max_height)
        self.settingsWidget.AOISettingY.slider.setValue(self.cameraWidget.max_height//4)

        self.settingsWidget.AOISettingWidth.slider.setMaximum(self.cameraWidget.max_width)
        self.settingsWidget.AOISettingWidth.slider.setValue(self.cameraWidget.max_width//2)

        self.settingsWidget.AOISettingHeight.slider.setMaximum(self.cameraWidget.max_height)
        self.settingsWidget.AOISettingHeight.slider.setValue(self.cameraWidget.max_height//2)

        # Initialisation of the exposure setting
        self.sensorSettingsWidget.exposureTime.floatListToSelect = self.cameraWidget.generateExpositionRangeList(1000)
        self.sensorSettingsWidget.exposureTime.slider.setRange(0, len(self.sensorSettingsWidget.exposureTime.floatListToSelect) - 1)

        self.sensorSettingsWidget.exposureTime.slider.valueChanged.connect(
            lambda : self.cameraWidget.camera.set_exposure(self.sensorSettingsWidget.exposureTime.value))

        self.sensorSettingsWidget.exposureTime.setValue(self.sensorSettingsWidget.exposureTime.floatListToSelect[-1])

        # Initialisation of the FPS setting
        minFPS, maxFPS = self.cameraWidget.getFPSRange()
        self.sensorSettingsWidget.FPS.slider.setMinimum(minFPS)
        self.sensorSettingsWidget.FPS.slider.setMaximum(maxFPS)

        self.sensorSettingsWidget.FPS.slider.valueChanged.connect(
            lambda : self.cameraWidget.camera.set_frame_rate(self.sensorSettingsWidget.FPS.getValue()))
        self.sensorSettingsWidget.FPS.slider.valueChanged.connect(
            lambda : print(f"FPS : {self.cameraWidget.camera.get_frame_rate()}"))
        
        self.sensorSettingsWidget.FPS.setValue(self.sensorSettingsWidget.FPS.getValue())

        # Initialisation of the BlackLevel setting
        self.sensorSettingsWidget.blackLevel.slider.setMinimum(0)
        self.sensorSettingsWidget.blackLevel.slider.setMaximum(256)
        self.sensorSettingsWidget.blackLevel.setValue(int(self.cameraWidget.camera.get_black_level())) # camera's blacklevel

        self.sensorSettingsWidget.blackLevel.slider.valueChanged.connect(
            lambda : self.cameraWidget.camera.set_black_level(self.sensorSettingsWidget.blackLevel.getValue()))

#-------------------------------------------------------------------------------------------------------

class MainWindow(QMainWindow):
    """
    Our main window.

    Args:
        QMainWindow (class): QMainWindow can contain several widgets.
    """
    def __init__(self):
        """
        Initialisation of the main Window.
        """
        super().__init__()

        # Variables
        self.oneOrFour = 4

        # Define Window title
        self.setWindowTitle("TP : Étude d'un capteur CMOS industriel")
        self.setWindowIcon(QIcon('IOGS-LEnsE-logo.jpg'))
        self.setGeometry(50, 50, 1600, 1200)

        # Set the widget as the central widget of the window
        self.mainWidget = MainWidget()
        self.setCentralWidget(self.mainWidget)

        # Setting the toolbar's buttons and the toolbar itself
        quitButton = QPushButton("Quit")
        quitButton.clicked.connect(lambda : self.close())

        AOISettingsButton = QPushButton("AOISettings")
        AOISettingsButton.clicked.connect(lambda : self.mainWidget.settingsWidget.show())

        startButton = QPushButton("Start")
        startButton.clicked.connect(lambda : self.mainWidget.cameraHistogramWidget.startMethod())
        startButton.clicked.connect(lambda : self.mainWidget.chartHistogramWidget.startMethod())
        startButton.clicked.connect(lambda : self.mainWidget.chartWidget.startMethod())

        stopButton = QPushButton("Stop")
        stopButton.clicked.connect(lambda : self.mainWidget.cameraHistogramWidget.stopMethod())
        stopButton.clicked.connect(lambda : self.mainWidget.chartHistogramWidget.stopMethod())
        stopButton.clicked.connect(lambda : self.mainWidget.chartWidget.stopMethod())

        saveButton = QPushButton("Save")
        saveButton.clicked.connect(lambda : self.mainWidget.chartWidget.saveMethod())

        clearButton = QPushButton("Clear")
        clearButton.clicked.connect(lambda : self.mainWidget.chartWidget.clearMethod())

        oneOrFourButton = QPushButton("I / IV")
        oneOrFourButton.clicked.connect(lambda : self.changeOneOrFour())

        self.AOIButton = QPushButton("AOI")
        self.AOIButton.clicked.connect(lambda : self.mainWidget.cameraWidget.launchAOI(
                                                            self.mainWidget.settingsWidget.AOIXGetValue(),
                                                            self.mainWidget.settingsWidget.AOIYGetValue(),
                                                            self.mainWidget.settingsWidget.AOIWidthGetValue(),
                                                            self.mainWidget.settingsWidget.AOIHeightGetValue()
                                                            ))
        toolbarMainWindow = self.addToolBar("Toolbar")
        toolbarMainWindow.setStyleSheet("background-color: #4472c4; border-radius: 10px; border-width: 1px;"
                           "border-color: black; padding: 6px; font: bold 12px; color: white;"
                           "text-align: center; border-style: solid;")

        for button in [quitButton, AOISettingsButton, self.AOIButton, startButton, stopButton, saveButton, clearButton, oneOrFourButton]:
            button.setStyleSheet("background-color: #7fadff; color: black;")

        toolbarMainWindow.addWidget(quitButton)
        separator0 = QAction(self)
        separator0.setSeparator(True)
        toolbarMainWindow.addAction(separator0)

        toolbarMainWindow.addWidget(AOISettingsButton)
        toolbarMainWindow.addWidget(self.AOIButton)

        # Add a separator between main's buttons and chart's button
        separator1 = QAction(self)
        separator1.setSeparator(True)
        toolbarMainWindow.addAction(separator1)

        toolbarMainWindow.addWidget(startButton)
        toolbarMainWindow.addWidget(stopButton)
        toolbarMainWindow.addWidget(saveButton)
        toolbarMainWindow.addWidget(clearButton)

        separator2 = QAction(self)
        separator2.setSeparator(True)
        toolbarMainWindow.addAction(separator2)
        toolbarMainWindow.addWidget(oneOrFourButton)

        # Launching the update methods
        self.mainWidget.cameraHistogramWidget.timerUpdate.timeout.connect(self.updateCameraHistogram)
        self.mainWidget.chartWidget.timerUpdate.timeout.connect(self.updateChart)
        self.mainWidget.chartHistogramWidget.timerUpdate.timeout.connect(self.updateChartHistogram)

    def updateCameraHistogram(self):
        """
        Update the camera's histogram with the new values.
        """
        # Get frame
        cameraFrame = self.mainWidget.cameraWidget.cameraFrame

        # Plot it
        self.mainWidget.cameraHistogramWidget.update(cameraFrame)

    def updateChartHistogram(self):
        """
        Update the chart's histogram with the new values.
        """
        # Get values
        ordinates = [self.mainWidget.chartWidget.ordinateAxis1,
                self.mainWidget.chartWidget.ordinateAxis2,
                self.mainWidget.chartWidget.ordinateAxis3,
                self.mainWidget.chartWidget.ordinateAxis4]
        
        # Plot it
        self.mainWidget.chartHistogramWidget.update(data = ordinates, numberOfPoints = self.oneOrFour)

    def updateChart(self):
        """
        Update the chart with the new values.
        """
        # Generate a data point
        newOrdinates = self.mainWidget.cameraWidget.getGraphValues()

        # Call the add_data_point method to add the new data point to the graph
        self.mainWidget.chartWidget.addOrdinatesPoints(ordinates = newOrdinates, numberOfPoints = self.oneOrFour)

    def changeOneOrFour(self):
        """
        Method used to change from the 4 points acquisition to the 1's one.
        """
        self.mainWidget.chartWidget.clearMethod()
        if self.oneOrFour == 4 :
            self.oneOrFour = 1

            # Print into the command prompt
            print(f"Acquisition : changed to {self.oneOrFour} point.")

        elif self.oneOrFour == 1:
            self.oneOrFour = 4

            # Print into the command prompt
            print(f"Acquisition : changed to {self.oneOrFour} points.")

#-------------------------------------------------------------------------------------------------------

# Launching as main for tests
if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MainWindow()
    window.show()

    sys.exit(app.exec_())
