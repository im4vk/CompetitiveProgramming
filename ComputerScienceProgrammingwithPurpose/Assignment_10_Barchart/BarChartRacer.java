import java.util.Arrays;

public class BarChartRacer {

    public static void main(String[] args) {
        StdDraw.enableDoubleBuffering();
        StdDraw.setCanvasSize(800, 800);

        String filename = args[0];
        int k = Integer.parseInt(args[1]);

        In reader = new In(filename);

        String title = reader.readLine();
        String xAxisLabel = reader.readLine();
        String dataSource = reader.readLine();

        BarChart barChart = new BarChart(title, xAxisLabel, dataSource);

        reader.readLine(); // blank line
        while (reader.hasNextLine()) {
            int n = Integer.parseInt(reader.readLine());
            Bar[] bars = new Bar[n];

            for (int i = 0; i < n; i++) {
                String line = reader.readLine();
                String[] arguments = line.split(",");
                bars[i] = new Bar(arguments[1], Integer.parseInt(arguments[3]), arguments[4]);
                barChart.setCaption(arguments[0]);
            }

            Arrays.sort(bars);

            for (int i = n - 1; i >= Math.max(n - k, 0); i--) {
                barChart.add(bars[i].getName(), bars[i].getValue(), bars[i].getCategory());
            }

            StdDraw.clear();
            barChart.draw();
            barChart.reset();
            StdDraw.show();
            StdDraw.pause(3);

            reader.readLine();
        }
    }
}