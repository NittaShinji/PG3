#include "Enemy.h"
#include "stdio.h"
#include <windows.h>
#include "time.h"

int Enemy::hp_ = 1;

//static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void(Enemy:: *Enemy::spFuncTable[])() =
{
	&Enemy::Move,	//�ڋ�
	&Enemy::Attack,	//�ˌ�
	&Enemy::Escape	//���E
};

//�R���X�g���N�^
Enemy::Enemy()
{
	phase_ = Phase::Approach;
}

Enemy::~Enemy(){}

//�ڋ�
void Enemy::Move()
{
	int second = 2;
	printf("��ԁF�ߐ�\n");

	//2�b�ԑ҂�
	Sleep(second * 1000);
	//�ˌ���ԂɕύX
	phase_ = Phase::Shooting;
}

//�U��
void Enemy::Attack()
{
	int second = 2;
	printf("��ԁF�ˌ�\n");

	//2�b�ԑ҂�
	Sleep(second * 1000);
	//���E��ԂɕύX
	phase_ = Phase::Leave;
}

//����
void Enemy::Escape()
{
	int second = 3;
	printf("��ԁF���E\n");

	//3�b�ԑ҂�
	Sleep(second * 1000);
	//�ڋߏ�ԂɕύX
	phase_ = Phase::Approach;
}

//�X�V
void Enemy::Update()
{
	//�f�o�b�O�p�\��
	printf("�G�̗̑� : %d\n", hp_);

	//���݂̃t�F�[�Y�̊֐������s
	(this->*spFuncTable[static_cast<size_t>(phase_)])();

}