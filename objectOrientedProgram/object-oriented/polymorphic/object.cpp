//**************************
// Author:  yh
// Time:    2022/4/19
//**************************

#include "object.h"

//��̬����
//1 PlayObj��������̨  ����һ�����
//15:20
void PlayObj(HeroFighter *hf, EnemyFighter *ef) {
    //��дvirtual�ؼ��� �Ǿ�̬���� C++����������HeroFighter����,ȥִ�� ������͵�power���� �ڱ���������׶ξ��Ѿ������˺����ĵ���
    //��̬����: �ٰ�:  //�����е�ʱ��,���ݾ������(���������),ִ�в�ͬ����ĺ��� ,���ֳɶ�̬.
    if (hf->power() > ef->attack())  //hf->power()�������û��ж�̬����
    {
        printf("����win\n");
    } else {
        printf("���ǹҵ�\n");
    }
}


//��̬��˼��
//�������3�����
//��װ: ͻ��c�����ĸ���....����������������ʱ��,����ʹ�ö�������� �Ͷ���ķ���
//�̳�: A B ���븴��
//��̬ : ����ʹ��δ��...


//��̬����Ҫ
//ʵ�ֶ�̬����������
//C���� ��Ӹ�ֵ ��ָ����ڵ��������
//��c���Ե����е����� (1 ������������  2 ��������  3 *p�ڱ����ú�����ȥ��ӵ��޸�ʵ�ε�ֵ)

//ʵ�ֶ�̬����������
//1 Ҫ�м̳�
//2 Ҫ���麯����д
//3 �ø���ָ��(��������)ָ���������....

void attack() {
    HeroFighter hf;
    AdvHeroFighter Advhf;
    EnemyFighter ef;

    AdvAdvHeroFighter advadvhf;

    PlayObj(&hf, &ef);
    PlayObj(&Advhf, &ef);

    PlayObj(&advadvhf, &ef); //������ �ܰ����Ǻ�����д�Ĵ���,����������
}

int main() {
    HeroFighter hf;
    AdvHeroFighter Advhf;
    EnemyFighter ef;

    if (hf.power() > ef.attack()) {
        printf("����win\n");
    } else {
        printf("���ǹҵ�\n");
    }

    if (Advhf.power() > ef.attack()) {
        printf("Adv ����win\n");
    } else {
        printf("Adv ���ǹҵ�\n");
    }
    return 0;
}
