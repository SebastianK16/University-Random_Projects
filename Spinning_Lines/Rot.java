import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.util.ArrayList;

public class Rot extends JPanel {
    private static final int WINDOW_WIDTH = 800;
    private static final int WINDOW_HEIGHT = 600;
    private static final int MENU_WIDTH = 150;
    private static final int MAX_Lines = 10;
    private static final int DEFAULT_LINE_LENGTH = 50;

    private ArrayList<Integer> LINELengths = new ArrayList<>();
    private ArrayList<ArrayList<Point>> lineTrajectories = new ArrayList<>();

    private int numLines = 1;
    private double rotationAngle = 0;

    public Rot() {
        setPreferredSize(new Dimension(WINDOW_WIDTH, WINDOW_HEIGHT));
        setLayout(new BorderLayout());
        setBackground(Color.BLACK);

        // Menu Panel
        JPanel menuPanel = new JPanel();
        menuPanel.setPreferredSize(new Dimension(MENU_WIDTH, 100));
        menuPanel.setLayout(new BoxLayout(menuPanel, BoxLayout.Y_AXIS));

        // Number of Lines Selector
        JLabel numLinesLabel = new JLabel("Number of Lines:");
        JSpinner numLinesSpinner = new JSpinner(new SpinnerNumberModel(1, 1, MAX_Lines, 1));
        numLinesSpinner.addChangeListener(e -> {
            numLines = (int) numLinesSpinner.getValue();
            updateLines();
        });
        numLinesSpinner.setPreferredSize(new Dimension(200, 100));
        menuPanel.add(numLinesLabel);
        menuPanel.add(numLinesSpinner);

        add(menuPanel, BorderLayout.WEST);

        // Lines Panel
        JPanel LinesPanel = new JPanel() {
            @Override
            protected void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                g2d.setColor(Color.WHITE);
                // Starting point at the center of the panel
                int centerX = getWidth() / 2;
                int centerY = getHeight() / 2;

                // Initial angle for the first line
                double angle = rotationAngle;

                // Add the lines
                for (int i = 0; i < numLines; i++) {
                    int LINELength = LINELengths.get(i);
                    ArrayList<Point> trajectory = lineTrajectories.get(i);
                    int startX = centerX;
                    int startY = centerY;
                    int endX = startX + (int) (LINELength * Math.sin(Math.toRadians(angle)));
                    int endY = startY + (int) (-LINELength * Math.cos(Math.toRadians(angle)));

                    g2d.drawLine(startX, startY, endX, endY);

                    // Update starting point and angle for the next line
                    centerX = endX;
                    centerY = endY;
                    angle += rotationAngle;

                    trajectory.add(new Point(endX, endY));
                    if (trajectory.size() > 150) {
                        trajectory.remove(0); // Keep trajectory limited in size
                    }
                }
                if (!lineTrajectories.isEmpty()) {
                    ArrayList<Point> lastTrajectory = lineTrajectories.get(lineTrajectories.size() - 1);
                    g2d.setColor(Color.RED);
                    for (int i = 1; i < lastTrajectory.size(); i++) {
                        Point p1 = lastTrajectory.get(i - 1);
                        Point p2 = lastTrajectory.get(i);
                        g2d.drawLine(p1.x, p1.y, p2.x, p2.y);
                    }
                }
            }   
        };
        LinesPanel.setBackground(Color.BLACK);
        add(LinesPanel, BorderLayout.CENTER);

        // Sliders Panel
        JPanel slidersPanel = new JPanel();
        slidersPanel.setLayout(new GridLayout(1, 10));

        // Initialize LINE lengths
        for (int i = 0; i < MAX_Lines; i++) {
            LINELengths.add(DEFAULT_LINE_LENGTH);
            lineTrajectories.add(new ArrayList<>());
            JSlider slider = createSlider(i);
            slidersPanel.add(slider);
        }

        add(slidersPanel, BorderLayout.SOUTH);

        Timer timer = new Timer(1, e -> {
            rotationAngle += 2;
            LinesPanel.repaint(); // update the Lines
        });
        timer.start();
    }

    private JSlider createSlider(int index) {
        JSlider slider = new JSlider(JSlider.HORIZONTAL, 0, 100, DEFAULT_LINE_LENGTH);
        slider.setMajorTickSpacing(20);
        slider.setMinorTickSpacing(10);
        slider.setPaintTicks(true);
        slider.setPaintLabels(true);
        slider.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                int value = ((JSlider) e.getSource()).getValue();
                LINELengths.set(index, value);
                repaint();
            }
        });
        return slider;
    }

    private void updateLines() {
        lineTrajectories.clear();
        for (int i = 0; i < numLines; i++) {
            LINELengths.add(DEFAULT_LINE_LENGTH);
            lineTrajectories.add(new ArrayList<>());
        }
        repaint();
    }
    
}
