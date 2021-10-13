public class Birthday {
public static void main(String[] args) {
      
        int n = Integer.parseInt(args[0]);
        int tr = Integer.parseInt(args[1]);
        //int randomNum = Integer.parseInt(args[2]);
      	int[] count = new int[n];
      double[] frac = new double[n];
      
      for(int i=0;i<tr;i++){
        int[] cnt = new int[n];
        //int k = (int) Math.random()*n;
        int per = 0;
        while(true){          
          int k = (int) (Math.random() * n);
          per++;
          if(cnt[k] == 1) break;
          else cnt[k] = 1;
        }        
        count[per]++;      
      }
      
      for (int i = 0; i < frac.length; i++) {
            int total = 0;
            for (int j = 0; j <= i; j++) {
                total += count[j];
            }
            frac[i] = (double) total / tr;
        }

        for (int i = 1; i < count.length; i++) {
            System.out.printf("%d%10d%10f\n", i, count[i], frac[i]);
            if (frac[i] >= 0.5) break;
        }

      
    }
}
