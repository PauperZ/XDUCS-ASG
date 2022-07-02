import java.util.Calendar;
import java.util.Scanner;
/**
 * @author ryzhao
 */
public class CalendarOutput
{
	public static int Days(int year,int month)
	{
	    int days=0;
	    if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	    {
	        days = 31;
	    }
	    else if(month==4||month==6||month==9||month==11)
	    {
	        days = 30;
	    }
	    else if(month==2)
	    {
	        if(year%4==0||year%400==0&&year%100!=0)
	        {
	            days = 29;
	        }
	        else
	        {
	           days = 28;
	        }
	     }
	    return days;
   }
	public static void main(String[] args)
	{
		int i=0,year=0,month=0,days=0,week=0,choice=0,j=0;
		Scanner sc  = new Scanner(System.in);
	    Calendar newc = Calendar.getInstance();
		while(true)
		{
			System.out.println("Menu:\n1.��ѯĳ������\n2.��ӡĳ������\n3.�˳�����\n���������ֽ���ѡ��");
			choice=sc.nextInt();
			if(choice==1)
			{
				System.out.println("���������");
				year=sc.nextInt();
				System.out.println("�������·�");
				month=sc.nextInt();
				System.out.println("����������");
				days=sc.nextInt();
				newc.set(year,month-1,days);
				week = newc.get(Calendar.DAY_OF_WEEK);
				switch(week)
				{
					case 1:
						System.out.print("������\n");
						break;
					case 2:
						System.out.print("����һ\n");
						break;
					case 3:	
						System.out.print("���ڶ�\n");
						break;
					case 4:	
						System.out.print("������\n");
						break;
					case 5:	
						System.out.print("������\n");
						break;
					case 6:	
						System.out.print("������\n");
						break;
					case 7:	
						System.out.print("������\n");
						break;
					
				}
			}
			else if(choice==2)
			{
				System.out.println("���������");
				year = sc.nextInt();
				for(j=0;j<12;j++)
				{
					System.out.println("-------------"+(j+1)+"��------------");
					days = Days(year,j+1);
				    newc.set(year,j,1);
				    week = newc.get(Calendar.DAY_OF_WEEK)-1;
				    int[] date =new int[40];
				    for(i=1;i<=days;i++)
				    {
				        date[week]=i;
				        week++;
				    }
				    System.out.println("��\tһ\t��\t��\t��\t��\t��");
				    for(i=0;i<week;i++)
				    {
				    	if(date[i]!= 0)
				        {
				    		System.out.print(date[i]+"\t");
				    		if((i+1)%7==0)
				    		{
				    			System.out.println("\n");
				            }
				        }
				    	else
				        {
				    		System.out.print(" "+"\t");
				        }

				    }
				    System.out.println("\n");
				}
		  
			}
			else if(choice==3) break;
		}
		sc.close();
	}
	
   
}