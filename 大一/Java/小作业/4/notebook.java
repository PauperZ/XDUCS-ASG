import java.util.ArrayList;
import java.util.Scanner;


public class notebook {
    static ArrayList<String> notebook = new ArrayList<String>();

    public static void main(String[] args) {
        int choice, num;
        String str;
        Scanner input = new Scanner(System.in);
        System.out.println("���±�����");
        // �˵�
        while (true) {
            System.out.println("---------------------------------");
            System.out.println("| 1 - ��¼			            |");
            System.out.println("| 2 - �޸ļ�¼		            |");
            System.out.println("| 3 - ��ѯ��¼��Ŀ			    |");
            System.out.println("| 4 - ��ѯ��¼����			    |");
            System.out.println("| 5 - ��ʾ���м�¼	            |");
            System.out.println("| 6 - ɾ�����м�¼	            |");
            System.out.println("| 7 - ɾ�����м�¼			    |");
            System.out.println("| 0 - �˳�����				    |");
            System.out.println("---------------------------------");
            System.out.println("�����������ִ�ж�Ӧ����:");

            choice = input.nextInt();

            // �˵���Ӧ���ܵ�ʵ��
            switch (choice){
                case 0:{
                    System.out.println("�����Ѿ��˳���");
                    input.close();
                    System.exit(0);
                    break;
                }
                case 1 :{
                    System.out.println("�������¼���ݣ�");
                    input.nextLine();
                    str = input.nextLine();
                    notebook.add(str);
                    System.out.println("�Ѽ�¼��");
                    break;
                }
                case 2 : {
                    System.out.println("��������Ҫ�޸ĵļ�¼���");
                    num = input.nextInt();
                    System.out.println("�������޸ĺ�����ݣ�");
                    input.nextLine();
                    str = input.nextLine();
                    notebook.set(num-1, str);
                    System.out.println("�޸ĳɹ���");
                    break;
                }
                case 3 :{
                    System.out.println("�Ѽ�¼��ĿΪ��"+notebook.size()+"��");
                    break;
                }
                case 4 :{
                    System.out.println("��������Ҫ�鿴�ļ�¼���");
                    num = input.nextInt();
                    showText(notebook,num);
                    break;
                }
                case 5 :{
                    showText(notebook,0);
                    break;
                }
                case 6 :{
                    System.out.println("������ɾ���鿴�ļ�¼���");
                    num = input.nextInt();
                    deleteText(notebook,num);
                    break;
                }
                case 7 :{
                    deleteText(notebook,0);
                    break;
                }
                default:{
                    System.out.println("û�ж�Ӧ���ܣ�������������룡");
                    break;
                }
            }

        }
    }
    // ��ʾ��¼��Ŀ
    public static void showText(ArrayList<String> text,int n){
        if(text.isEmpty()){
            System.out.println("��ǰ��û�м�¼��");
        }
        else {
            if (n == 0) {
                for (int i = 0; i < text.size(); i++) {
                    System.out.println((i+1)+":"+notebook.get(i));
                }
            }else if (n > 0 && n <= text.size()) {
                System.out.println(n+":"+notebook.get(n-1));
            }else {
                System.out.println("�����������������룡");
            }
        }
    }
    // ɾ����¼��Ŀ
    public static void deleteText(ArrayList<String> text,int n){
        if (text.isEmpty()) {
            System.out.println("��ǰ�޼�¼");
        }else {
            if(n==0){
                text.clear();
                System.out.println("�Ѿ����ȫ����¼");
            }else if (n > 0 && n<= text.size()) {
                text.remove(n-1);
                System.out.println("�Ѿ������"+n+"����¼");
            }else {
                System.out.println("����������������룡");
            }
        }
    }
}
