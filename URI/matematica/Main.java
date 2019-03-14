import java.io.IOException;
import java.util.Scanner;
import java.math.BigInteger;
import java.math;
public class Main {
 
    public static void main(String[] args) throws IOException {
 
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++){
            BigInteger N = sc.nextBigInteger(), C = sc.nextBigInteger();
            BigInteger NPC = N.add(C).subtract(BigInteger.ONE);
            int max = C.subtract(BigInteger.ONE).intValue();
            for (int j = 1; j <= max; j++)
                NPC = NPC.multiply(N.add(BigInteger.valueOf(max - j)));
            BigInteger res = (NPC.divide(factorial(C))).mod(BigInteger.valueOf(1300031));
            System.out.println(res);
        }
 
    }
    
    public static BigInteger factorial(BigInteger n) {
        
        

        return result;
    }
}

