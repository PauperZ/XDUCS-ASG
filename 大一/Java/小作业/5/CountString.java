import java.io.File;
import java.util.Scanner;
import java.util.regex.Pattern;


public class CountString {
    private static boolean isletter(char letter) {
        return (letter >= 'a' && letter <= 'z' || letter >= 'A' && letter <= 'Z');
    }

    static int countletter(File file) throws Exception {
        Scanner input = new Scanner(file);
        int sum = 0;
        while (input.hasNext()) {
            String str = input.next();
            char[] a = str.toCharArray();
            for (char c : a) {
                if (isletter(c)) {
                    sum++;
                }
            }
        }
        input.close();
        return sum;
    }

    static int countstring(File file) throws Exception {
        Scanner input = new Scanner(file);
        int sum = 0;
        while (input.hasNext()) {
            input.next();
            sum++;
        }
        input.close();
        return sum;
    }

    public static void loop() throws Exception {
        Scanner in = new Scanner(System.in);
        System.out.println("��ͳ���ı����뱾java�ļ�����ͬһĿ¼�£�");
        System.out.println("��������Ҫͳ�Ƶ��ı��ļ����ƣ�(����Ҫ�����׺)");
        String filename = in.nextLine();
        File file = new File("src/" + filename + ".txt");
        if (!file.exists()) {
            System.out.println("û�и��ļ����������룡");
            System.exit(0);
        }
        Scanner in2 = new Scanner(System.in);
        System.out.println("�˵���\n1.ͳ��Ӣ���ַ���Ŀ��\n2.ͳ���ַ�����Ŀ��\n3.ͳ��ȫ����Ϣ��\n4.�˳���");
        System.out.println("��ƥ�䵽���ļ���������˵�����Լ�����");
        int choice = in2.nextInt();
        switch (choice) {
            case 1: {
                System.out.println("�ļ��е�Ӣ���ַ�����Ϊ��" + CountString.countletter(file));
                break;
            }
            case 2: {
                System.out.println("�ļ��е��ַ�������Ϊ��" + CountString.countstring(file));
                break;
            }
            case 3: {
                System.out.println("�ļ��е�Ӣ���ַ�����Ϊ��" + CountString.countletter(file));
                System.out.println("�ļ��е��ַ�������Ϊ��" + CountString.countstring(file));
                break;
            }
            case 4: {
                System.out.println("�������˳���");
                System.exit(0);
                break;
            }
            default: {
                System.out.println("û�и�ѡ�������ѡ��");
                break;
            }
        }
        in.close();
        in2.close();
    }

    public static void main(String[] args) throws Exception {
        loop();
    }
}
