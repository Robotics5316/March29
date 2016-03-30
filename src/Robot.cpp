#include "WPILib.h"
#include "UserInterface.h"
#include <stdio.h>
#include <string>
#include "DriveTrain/TankDrive.h"
#include "Shooter.h"
#include "Camera.h"
#include "Leddar.h"
#include "DriveTrain/SuspensionDrive.h"

//The Robot's name is "grass hopper"

class Robot: public IterativeRobot {
private:
	TankDrive m_tank;
	CANTalon* LEFTDRIVE1;
	CANTalon* LEFTDRIVE2;
	CANTalon* RIGHTDRIVE1;
	CANTalon* RIGHTDRIVE2;
	CANTalon* TOPMOTOR1;

	//Talon* m_PWMTalonRightRearTop;		//just need a Talon with PWM to operate it. Same with all the rest of PWMTalons
	//Talon* m_PWMTalonLeftRearTop;
	//Talon* m_PWMTalonRightFrontTop;
	//Talon* m_PWMTalonLeftFrontTop;


	Encoder* leftEncoder;
	Encoder* rightEncoder;

	//Talon* LeftWheels;
	//Talon* RightWheels;
	//CANTalon* LeftCANWheels;
	//CANTalon* RightCANWheels;

	SuspensionDrive m_suspension;
	Shooter m_shooter;
	//Leddar m_leddar;
	UserInterface ui;
	WedgemoreUserInput wui;
	Joystick* m_lStick;
	Joystick* m_rStick;
	//Joystick* m_manStick;
	//Camera* Cam0;
	RobotDrive* drive;
	//Robot* myRobot;

	LiveWindow *lw = LiveWindow::GetInstance();
	SendableChooser *chooser = nullptr;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

	float autoSpeed = 0;

public:


	void RobotInit() {

		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

		chooser = new SendableChooser();
		chooser->AddDefault(autoNameDefault, (void*) &autoNameDefault);
		chooser->AddObject(autoNameCustom, (void*) &autoNameCustom);
		SmartDashboard::PutData("Auto Modes", chooser);
		SmartDashboard::PutString("hello", "I'm here");
		//LEFTDRIVE1 = new CANTalon(3);
		//LEFTDRIVE2 = new CANTalon(2);
		//RIGHTDRIVE1 = new CANTalon(1);
		//RIGHTDRIVE2 = new CANTalon(4);
		LEFTDRIVE1 = new CANTalon(1);
		LEFTDRIVE2 = new CANTalon(4);
		RIGHTDRIVE1 = new CANTalon(3);
		RIGHTDRIVE2 = new CANTalon(2);
		TOPMOTOR1 = new CANTalon(5);

		//m_canTalonRightRear + m_canTalonRightFront = new CANTalon(RightCANWheels);
		//m_canTalonLeftRear + m_canTalonLeftFront = new CANTalon (LeftCANWheels);
		//m_PWMTalonRightRearTop + m_PWMTalonRightFrontTop = new Talon(RightWheels);
		//m_PWMTalonLeftRearTop + m_PWMTalonLeftFrontTop = new Talon(LeftWheels);

	//	m_PWMTalonRightRearTop = new Talon(8);
	//	m_PWMTalonRightFrontTop = new Talon(6);
	//	m_PWMTalonLeftRearTop = new Talon(9);
	//	m_PWMTalonLeftFrontTop = new Talon(7);



		m_lStick = new Joystick(1);
		//m_rStick = new Joystick(0);

		//drive = new RobotDrive(RightCANWheels, LeftCANWheels, RightWheels, LeftWheels);

		//drive = new RobotDrive(m_PWMTalonLeftFrontTop, m_PWMTalonLeftRearTop,m_PWMTalonRightFrontTop, m_PWMTalonRightRearTop);
		drive = new RobotDrive(LEFTDRIVE1, LEFTDRIVE2, RIGHTDRIVE1, RIGHTDRIVE2);

		//drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		//drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
		//drive->SetInvertedMotor(RobotDrive::kRearRightMotor, false);

		leftEncoder = new Encoder(0, 1);
		rightEncoder = new Encoder(2, 3);
	}


	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString line to get the auto name from the text box
	 * below the Gyro
	 *s
	 * You can add additional auto modes by adding additional comparisons to the if-else structure below with additional strings.
	 * If using the SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() {
		autoSelected = *((std::string*) chooser->GetSelected());
		std::string autoSelected = SmartDashboard::GetString("Auto Selector",
				autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;


		//myRobot.SetSafetyEnabled(false);
		//myRobot.Drive(-0.5, 0.0);

		if (autoSelected == autoNameCustom) {
			//Custom Auto goes here
			//autoSpeed = 1;
			//Wait(2);
			//autoSpeed = 0;
		} else {
			//Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (autoSelected == autoNameCustom) {
		//	m_canTalonLeftFront->Set(autoSpeed);
		//	m_canTalonLeftRear->Set(autoSpeed);
		//	m_canTalonRightFront->Set(autoSpeed);
		//	m_canTalonRightRear->Set(autoSpeed);

		//	autoSpeed = 1;
		//	Wait(2);
		//	autoSpeed = 0;

		} else {
		//	//		Default Auto goes here
		}
	}

	void TeleopInit() {

	}
	//void StartAutomaticCapture(std::shared_ptr<USBCamera>cam0);
	void TeleopPeriodic() {
//		ui.GetData(&wui);
//		m_tank.Drive(wui.LeftSpeed, wui.RightSpeed);
//
//		m_shooter.Rotate(wui.RotateSpeed*3); //70 degrees per second at full value
//		m_shooter.Lift(wui.LiftSpeed*1.193); //4 seconds for 180 degree revolution
//		if(wui.SpinUp) {
//			m_shooter.Spinup(1);
//		}
//		if(wui.Shoot) {
//			m_shooter.Shoot();
//		}
//		if(wui.Pickup) {
//			m_shooter.Pickup();
//		}
//
//		m_suspension.SetFrontLeft(wui.DropFL);
//		m_suspension.SetBackLeft(wui.DropBL);
//		m_suspension.SetFrontRight(wui.DropFR);
//		m_suspension.SetBackRight(wui.DropBR);

//		m_leddar.GetDetections();
//		m_shooter.Update();
		//float RTrigger = m_lStick->GetRawAxis(3);
		//float LTrigger = m_lStick->GetRawAxis(2);

		//if (m_PWMTalonLeftFrontTop == .5)
		//if (abs(RTrigger) < 0.2)
			//RTrigger = 0;
		//if (abs(LTrigger) < 0.2)
			//LTrigger = 0;
		float leftSpeed = m_lStick->GetRawAxis(1);
		float rightSpeed = m_lStick->GetRawAxis(5);
		if (abs(leftSpeed) < 0.2)
			leftSpeed = 0;
		if (abs(rightSpeed) < 0.2)
			rightSpeed = 0;
		//float LTrigger = m_lStick->GetRawAxis(3);
		//float RTrigger = m_lStick->GetRawAxis(2);
		SmartDashboard::PutNumber("Left Stick", leftSpeed);
		SmartDashboard::PutNumber("Right Stick", rightSpeed);
		//SmartDashboard::PutNumber("L Trigger", LTrigger);
		//SmartDashboard::PutNumber("R Trigger", RTrigger);
		SmartDashboard::PutNumber("Left Encoder", leftEncoder->Get());
		SmartDashboard::PutNumber("Right Encoder", rightEncoder->Get());
		drive->TankDrive(leftSpeed, rightSpeed, true);
		//drive->TankDrive(RTrigger, LTrigger, true);
		LEFTDRIVE1->Set(leftSpeed);
		LEFTDRIVE2->Set(leftSpeed);
		RIGHTDRIVE1->Set(rightSpeed);
		RIGHTDRIVE2->Set(rightSpeed);
		//m_PWMTalonLeftFrontTop->Set(RTrigger);
		//m_PWMTalonRightFrontTop->Set(RTrigger);
		//m_PWMTalonRightRearTop->Set(LTrigger);
		//m_PWMTalonLeftRearTop->Set(LTrigger);
	}

	void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
