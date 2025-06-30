#include <DxLib.h>
#include "Application/Application.h"

// WinMain�֐�
//---------------------------------
int WINAPI WinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	// �C���X�^���X�̐���
	Application::CreateInstance();

	// �C���X�^���X�̎擾
	Application::GetInstance()->Init();

	if (Application::GetInstance()->IsInitFail())
	{
		// ���������s
		return -1;
	}

	// ���s
	Application::GetInstance()->Run();

	// ���
	Application::GetInstance()->Release();

	if (Application::GetInstance()->IsReleaseFail())
	{
		// ������s
		return -1;
	}

	// �C���X�^���X�̍폜
	Application::DeleteInstance();

	return 0;
}
