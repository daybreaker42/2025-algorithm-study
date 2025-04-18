import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]), m = Integer.parseInt(line[1]);
        int[] a = new int[1000001];
        int x = 0, idx = 0;

        line = br.readLine().split(" ");
        for (int i = 0; i<n; i++) {
            a[i] = Integer.parseInt(line[i]);
        }

        line = br.readLine().split(" ");
        for (int i = 0; i<m; i++) {
            x = Integer.parseInt(line[i]);
            while (idx < n && a[idx] < x) {
                bw.write(String.valueOf(a[idx++]) + " ");
            }
            bw.write(String.valueOf(x) + " ");
        }
        while(idx < n) {
            bw.write(String.valueOf(a[idx++]) + " ");
        }
        bw.flush();
        bw.close();
    }
}
