//#include "x2Genetic.h"
//using namespace std;
////�Ա���ȡֵ��Χ��������Ⱥ��������
//const X_Range Range = { X_Range(-3.0,12.1) };//�Ա��������߻���x1,x2��ȡֵ��Χ
//vector<Individual> nowpopulation;//P(t)��Ⱥ
//vector<Individual> midpopulation;//�м���Ⱥ���������ѡ�����������
//vector<Individual> nextpopulation;//P(t+1)��Ⱥ
////X_Range��ʵ��
//X_Range::X_Range(double m_Lower, double m_Upper) :Lower(m_Lower), Upper(m_Upper) {}//X_Range�๹�캯��ʵ��
//double X_Range::GetUpper()const//��ȡ��������
//{
//    return Upper;
//}
//double X_Range::GetLower()const//��ȡ��������
//{
//    return Lower;
//}
////Individual��ʵ��
//Individual::Individual(double m_Variable)//���캯��
//{
//   
//    
//        if (m_Variable >= Range.GetLower() && m_Variable <= Range.GetUpper())//����Ҫ�����Ա���ȡֵ��Χ�ж�
//        {
//            Variable = m_Variable;//�Ա�����ֵ
//        }
//        else//������Ҫ���򷢳������沢����
//        {
//            cerr << "�Ա���ȡֵ������Ҫ��" << endl;
//            exit(1);//ֹͣ�����һ�����������ķ�ʽ�����Ա�����ֵ(����ֵ)������˵������ֵ���ڹ涨��Χ��
//        }
//    
//    //��ʼ��ʱĬ����Ӧֵ��ֵΪ0
//    this->Fitness = 0;
//    this->ReFitness = 0;
//    this->SumFitness = 0;
//}
//double Individual::GetVariable()//��ȡ����ֵ
//{
//    return Variable;
//}
//double Individual::GetFitness()const//��ȡ��Ӧֵ
//{
//    return Fitness;
//}
//double Individual::GetReFitness()const //��ȡ��Ӧֵ����
//{
//    return ReFitness;
//}
//double Individual::GetSumFitness()const//��ȡ�ۼӸ���
//{
//    return SumFitness;
//}
//void Individual::ChaFitness(const double m_fitness)//�޸���Ӧֵ
//{
//    this->Fitness = m_fitness;
//}
//void Individual::ChaReFitness(const double m_ReFitness)//�޸���Ӧֵ����
//{
//    this->ReFitness = m_ReFitness;
//}
//void Individual::ChaSumFitness(const double m_SumFitness)//�޸��ۼӸ���
//{
//    this->SumFitness = m_SumFitness;
//}
////�Ŵ��㷨��׼������
//void Initialize()//�����ʼ����Ⱥ���õ���һ����Ⱥ
//{
//    //����ָ����Χ���������������
//    double X[Po_Size];//Ϊ��ʹ������������Ԫ������ֵ�ļ��㣬�þ��󱣴���������������ֵ
//    default_random_engine e(time(0));//���棬�����������
//    uniform_real_distribution<double> u(Range.GetLower(), Range.GetUpper());//�ֲ�
//    for (int i = 0; i < Po_Size; i++)//�Ȱ��д洢�����
//    {
//         X[i] = u(e);//ѭ������ʱ���������ֵ�ͱ�����X������
//    }
//    
//    //���ɶ���Ⱦɫ�壩�����뵽��ʼ��Ⱥ��
//    for (int i = 0; i < Po_Size; i++)
//    {
//        double variable;
//        
//            variable = X[i];//���б���
//        
//        Individual Indivi(variable);//����һ������Ⱦɫ�壩
//        nowpopulation.push_back(Indivi);//���뵽��Ⱥpopulation��
//    }
//}
//void CaculaFitness()//����������Ӧֵ
//{
//    //f(x) = x^2+1 Ϊ��Ӧ�ȼ��㺯��
//    double fitness = 0;//��ʱ��Ӧֵ
//    double x;//��ʱ�洢�Ա���������
//    for (int i = 0; i < Po_Size; i++)
//    {
//        
//        x = nowpopulation.at(i).GetVariable();//������ֱ��
//        fitness =(x*x)+ 1;//��Ӧ�ȼ��� 
//        nowpopulation.at(i).ChaFitness(fitness);//�޸ĵ�ǰȾɫ�����Ӧֵ
//    }
//}
//void CaculaReFitness()//������Ӧֵ����
//{
//    double sum = 0;//��Ӧֵ�ۼ���
//    double temp = 0;
//    for (int i = 0; i < Po_Size; i++)//�������Ӧֵ֮��
//    {
//        sum += nowpopulation.at(i).GetFitness();
//    }
//    for (int j = 0; j < Po_Size; j++)
//    {
//        temp = nowpopulation.at(j).GetFitness() / sum;//�������
//        nowpopulation.at(j).ChaReFitness(temp);//�޸ĸ������Ӧ�ȸ���
//    }
//}
//void CalculaSumFitness()//�����ۼӸ������
//{
//    double summation = 0;//�ۼ���
//    for (int k = 0; k < Po_Size; k++)
//    {
//        summation += nowpopulation.at(k).GetReFitness();
//        nowpopulation.at(k).ChaSumFitness(summation);//��ǰ�ۼӽ����ֵ
//    }
//}
//void seclect() //��Ⱥѡ��
//{
//    //���������0��1��С��
//    double array[Po_Size];//������������
//    default_random_engine e(time(0));//���棬�����������
//    uniform_real_distribution<double> u(0.0, 1.0); //�ֲ�
//    for (int i = 0; i < Po_Size; i++)
//        array[i] = u(e);
//    //���̽���ѡ��
//    for (int j = 0; j < Po_Size; j++)
//    {
//        for (int i = 1; i < Po_Size; i++)
//        {
//            if (array[j] < nowpopulation[i - 1].GetSumFitness())
//            {
//                midpopulation.push_back(nowpopulation.at(i - 1));//���뵽�м���Ⱥ
//            }
//            if (array[j] >= nowpopulation.at(i - 1).GetSumFitness() && array[j] <= nowpopulation.at(i).GetSumFitness())
//            {
//                midpopulation.push_back(nowpopulation.at(i));//���뵽�м���Ⱥ
//            }
//        }
//    }
//    nowpopulation.clear();//���nowpopulation
//}
//double Scand() //�������0��1��С��
//{
//    int N = rand() % 999;
//    return double(N) / 1000.0;;//�������0��1��С��
//}
//void crossing()//�ӽ�
//{
//    int num = 0;//��¼����
//    double corss = 0.0;//������������ĸ���ֵ
//    srand((unsigned)time(NULL));//����ϵͳʱ���������������,����һ��������Ӿ���
//    double array1, array2;//��ʱ�洢���׺�ĸ�׵ı���ֵ
//    while (num < Po_Size - 1)//����1�����2�ӽ�������3�����4�ӽ�......����i�͸���i+1�ӽ�
//    {
//        //�ж�˫���Ƿ���Ҫ�ӽ����������һ��0��1��С�����������������ӽ����ʣ�������ӽ���ֱ���Ŵ�����һ�������򣬶Ը�ĸ������ӽ�
//        corss = Scand();
//        if (corss <= Ov_Probability)//���corssС�ڵ����ӽ�����Ov_Probability�ͽ��е����ӽ�
//        {
//            //����Ѱ�Ҷ�Ӧ�±�ĸ��岢�ұ���
//            
//                array1 = midpopulation.at(num).GetVariable();//���׵��Ա���
//                array2 = midpopulation.at(num + 1).GetVariable();//ĸ���Ա���
//            
//            int localx1, localx2;//��¼���򽻲���λ��
//            int corssx[length];//��Ϊ�������������
//            double newx1, newx2;//�ֱ�����������򽻻�������Ӧ�Ա���ֵ
//            bool p1 = true, p2 = true;
//            //Ȼ���˫�ױ������б��벢�ҽ��е����ӽ�
//           
//                
//                
//            bitset<length> array1b2((array1) * pow(10, 6));//ĸ��1��x2����
//            bitset<length> array2b2((array2) * pow(10, 6));//ĸ��2��x2����
//            //�����������0��length2-1������ȷ��������λ��
//            localx2 = rand() % length;
//            //���ڽ��е��㽻�棬����˫��localx2����Ļ���
//            for (int i = 0; i < localx2; i++)
//                corssx[i] = array1b2[i];
//            for (int k = 0; k < localx2; k++)
//                array1b2[k] = array2b2[k];
//            for (int s = 0; s < localx2; s++)
//                array2b2[s] = corssx[s];
//            //��ֵ������newx2�����У�x2������ɵ����ӽ�����
//            newx1 = double(array1b2.to_ullong()) / pow(10, 6);
//            newx2 = double(array2b2.to_ullong()) / pow(10, 6);
//            //���²�����ֵ�����жϣ��ж��Ƿ񳬳���Χ�����������Χ���ӽ�
//            if (newx1< Range.GetLower() || newx1>Range.GetUpper() || newx2<Range.GetLower() || newx2>Range.GetUpper())
//            {
//                p2 = false;
//                break;
//            }
//                
//            
//            if (p1 == true && p2 == true)
//            {
//                Individual newchiled1(newx1);
//                Individual newchiled2(newx2);
//                nextpopulation.push_back(newchiled1);
//                nextpopulation.push_back(newchiled2);
//            }
//            else//��ԭ���ĸ����Ŵ�����һ��
//            {
//                nextpopulation.push_back(midpopulation.at(num));
//                nextpopulation.push_back(midpopulation.at(num + 1));
//            }
//        }
//        else//����ֱ���Ŵ�����һ��nextpopulation
//        {
//            nextpopulation.push_back(midpopulation.at(num));//����һ���µĸ��岢�Ҽ��뵽nextpopulation��
//            nextpopulation.push_back(midpopulation.at(num + 1));
//        }
//        num += 2;
//    }
//    midpopulation.clear();//���midpopulation
//}
//void variating()//����
//{
//    int num = 0;
//    while (num < Po_Size)
//    {
//        double variation = Scand();//�������һ��0��1��С���������ж��Ƿ���б���
//        if (variation <= Va_Probability)//���variationС�ڱ���ϵ��������Ҫ���б���
//        {
//            double x;
//            bool p = true;
//            int xlocal, 
//            x = nextpopulation.at(num).GetVariable();
//            bitset<length> array(x * pow(10, 6));//x����
//            xlocal = rand() % length;//array��λȡ��
//           
//            
//            array.flip(xlocal);//�ı�array2 x2localλ��״̬
//           
//            x = double(array.to_ullong()) / pow(10, 6);
//            //�ж��Ƿ��������
//            if (x< Range.GetLower() || x>Range.GetUpper() || x<Range.GetLower() || x>Range.GetUpper())
//                p = false;
//            if (!p)//��������ϣ��򽫲������ֵ�����µ�����
//                nowpopulation.push_back(nextpopulation.at(num));
//            if (p) //pΪ��Ļ����������ļ����µ�������е���
//            {
//                Individual newchiled(x);
//                nowpopulation.push_back(newchiled);
//            }
//        }
//        else //������
//            nowpopulation.push_back(nextpopulation.at(num));
//        num++;
//    }
//    nextpopulation.clear();//���nextpopulation
//}
//void genetic_algorithm()
//{
//    Initialize();//��ʼ����Ⱥ,������ɵ�һ������
//    //����500��
//    for (int i = 0; i < Ev_Algebra; i++)
//    {
//        CaculaFitness();//��Ӧ�ȼ���
//        CaculaReFitness();//��Ӧ�ȸ��ʼ���
//        CalculaSumFitness();//�����ۼӸ������
//        seclect();//ѡ��
//        crossing();//�ӽ�
//        variating();//����
//    }
//    CaculaFitness();//��Ӧ�ȼ���
//    double maxfitness = nowpopulation.at(0).GetFitness();
//    int maxid = 0;
//    int k;
//    for (k = 0; k < Po_Size; k++)
//    {
//        if (maxfitness < nowpopulation.at(k).GetFitness())
//        {
//            maxfitness = nowpopulation.at(k).GetFitness();
//            maxid = k;
//        }
//    }
//    //����500��֮�����
//    cout << "x" << setw(15) << "Fitness" << endl;
//    for (int j = 0; j < Po_Size; j++)
//        cout << nowpopulation.at(j).GetVariable() << setw(10)  << nowpopulation.at(j).GetFitness() << endl;
//    cout << "x=" << nowpopulation.at(maxid).GetVariable()  << "ʱȡ�����ֵ��" << maxfitness << endl;
//}
//int main()
//{
//    genetic_algorithm();
//    return 0;
//}
// 
// 
