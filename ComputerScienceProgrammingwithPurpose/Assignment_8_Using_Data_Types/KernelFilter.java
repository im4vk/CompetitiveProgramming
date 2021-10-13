import java.awt.Color;

public class KernelFilter {

    // Returns a new picture that applies a Gaussian blur filter to the given picture.
    public static Picture gaussian(Picture picture) {
        
    Picture patch = new Picture(picture.width() + 2, picture.height() + 2);
    
    for (int col = 1; col < (patch.width() - 1); col++) {  //center elements copied from original picture
        for (int row = 1; row < (patch.height() - 1); row++) {
            Color color = picture.get((col - 1), (row - 1));
            patch.set(col, row, color);
        }
    }
    
    for(int col = 0; col < patch.width(); col += (patch.width() - 1)) { //left & right patch elements
        for (int row = 1; row < (patch.height() - 1); row++) {
            if (col == 0) {
                Color color = picture.get((picture.width() - 1), (row - 1));
                patch.set(col, row, color);
            }
            if (col == (patch.width() - 1)) {
                Color color = picture.get(0, (row - 1));
                patch.set(col, row, color);
            }
        }
    }
    //System.out.println("patch.wisth = " + patch.width());
    for (int row = 0; row < patch.height(); row += (patch.height() - 1)) { //up & down 2 patch elements
        for (int col = 0; col < patch.width(); col++) {
            if (row == 0) {
                Color color = patch.get(col, patch.height() -2);
                patch.set(col, row, color);
            }
            if (row == (patch.height() - 1)) {
                //System.out.println("col = " + col);
                Color color = patch.get(col, 1);
                patch.set(col, row, color);
            }
        }
    }
    
    double[][] Gaussian = new double[3][3]; //define kernel
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        if ((i + j) % 2 == 1) Gaussian[i][j] = 1.0 / 8.0; 
        if ((i + j) % 2 == 0) Gaussian[i][j] = 1.0 / 16.0;
        if (i == 1 && j == 1) Gaussian[i][j] = 1.0 / 4.0;
        }
    }
           
    Picture target = new Picture(picture.width(), picture.height()); //define processed picture
    double sumR = 0;
    double sumG = 0;
    double sumB = 0;
    
    for (int row = 1; row < patch.height() - 1; row++) {                      //Multiplying Kernel
        for (int col = 1; col < patch.width() -1; col ++) {
            
            for (int i = -1; i < 2; i++) {            //within 3X3 kernel X Pixel
                for (int j = -1; j < 2; j++){
                    Color colorS = patch.get(col + j, row + i);
                    int r = colorS.getRed();
                    int g = colorS.getGreen();
                    int b = colorS.getBlue();
                    sumR += (r * Gaussian[i + 1][j + 1]); 
                    sumG += (g * Gaussian[i + 1][j + 1]);
                    sumB += (b * Gaussian[i + 1][j + 1]);            
                }
            }
            int R = (int) Math.round(sumR);
            int G = (int) Math.round(sumG);
            int B = (int) Math.round(sumB);
            if (R > 255) R = 255;
            if (G > 255) G = 255;
            if (B > 255) B = 255;
            if (R < 0) R = 0;
            if (G < 0) G = 0;
            if (B < 0) B = 0;
            Color colorT = new Color(R, G, B);
            target.set(col - 1, row - 1, colorT);
            sumR = 0;
            sumG = 0;
            sumB = 0;        
        }
    }
    return target;
    }

    //Returns a new picture that applies a sharpen filter to the given picture.
    public static Picture sharpen(Picture picture) {
                
    Picture patch = new Picture(picture.width() + 2, picture.height() + 2);
    
    for (int col = 1; col < (patch.width() - 1); col++) {  //center elements copied from original picture
        for (int row = 1; row < (patch.height() - 1); row++) {
            Color color = picture.get((col - 1), (row - 1));
            patch.set(col, row, color);
        }
    }
    
    for(int col = 0; col < patch.width(); col += (patch.width() - 1)) { //left & right patch elements
        for (int row = 1; row < (patch.height() - 1); row++) {
            if (col == 0) {
                Color color = picture.get((picture.width() - 1), (row - 1));
                patch.set(col, row, color);
            }
            if (col == (patch.width() - 1)) {
                Color color = picture.get(0, (row - 1));
                patch.set(col, row, color);
            }
        }
    }
    //System.out.println("patch.wisth = " + patch.width());
    for (int row = 0; row < patch.height(); row += (patch.height() - 1)) { //up & down 2 patch elements
        for (int col = 0; col < patch.width(); col++) {
            if (row == 0) {
                Color color = patch.get(col, patch.height() -2);
                patch.set(col, row, color);
            }
            if (row == (patch.height() - 1)) {
                //System.out.println("col = " + col);
                Color color = patch.get(col, 1);
                patch.set(col, row, color);
            }
        }
    }
    
    double[][] Sharpen = new double[3][3]; //define kernel
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        if ((i + j) % 2 == 1) Sharpen[i][j] = -1.0; 
        if (i == 1 && j == 1) Sharpen[i][j] = 5.0;
        }
    }
           
    Picture target = new Picture(picture.width(), picture.height()); //define processed picture
    double sumR = 0;
    double sumG = 0;
    double sumB = 0;
    
    for (int row = 1; row < patch.height() - 1; row++) {                      //Multiplying Kernel
        for (int col = 1; col < patch.width() -1; col ++) {
            
            for (int i = -1; i < 2; i++) {            //within 3X3 kernel X Pixel
                for (int j = -1; j < 2; j++){
                    Color colorS = patch.get(col + j, row + i);
                    int r = colorS.getRed();
                    int g = colorS.getGreen();
                    int b = colorS.getBlue();
                    sumR += (r * Sharpen[i + 1][j + 1]); 
                    sumG += (g * Sharpen[i + 1][j + 1]);
                    sumB += (b * Sharpen[i + 1][j + 1]);            
                }
            }
            int R = (int) Math.round(sumR);
            int G = (int) Math.round(sumG);
            int B = (int) Math.round(sumB);
            if (R > 255) R = 255;
            if (G > 255) G = 255;
            if (B > 255) B = 255;
            if (R < 0) R = 0;
            if (G < 0) G = 0;
            if (B < 0) B = 0;
            Color colorT = new Color(R, G, B);
            target.set(col - 1, row - 1, colorT);
            sumR = 0;
            sumG = 0;
            sumB = 0;        
        }
    }
    return target;   
    }

    //Returns a new picture that applies an Laplacian filter to the given picture.
    public static Picture laplacian(Picture picture) {
        Picture patch = new Picture(picture.width() + 2, picture.height() + 2);
    
    for (int col = 1; col < (patch.width() - 1); col++) {  //center elements copied from original picture
        for (int row = 1; row < (patch.height() - 1); row++) {
            Color color = picture.get((col - 1), (row - 1));
            patch.set(col, row, color);
        }
    }
    
    for(int col = 0; col < patch.width(); col += (patch.width() - 1)) { //left & right patch elements
        for (int row = 1; row < (patch.height() - 1); row++) {
            if (col == 0) {
                Color color = picture.get((picture.width() - 1), (row - 1));
                patch.set(col, row, color);
            }
            if (col == (patch.width() - 1)) {
                Color color = picture.get(0, (row - 1));
                patch.set(col, row, color);
            }
        }
    }
    //System.out.println("patch.wisth = " + patch.width());
    for (int row = 0; row < patch.height(); row += (patch.height() - 1)) { //up & down 2 patch elements
        for (int col = 0; col < patch.width(); col++) {
            if (row == 0) {
                Color color = patch.get(col, patch.height() -2);
                patch.set(col, row, color);
            }
            if (row == (patch.height() - 1)) {
                //System.out.println("col = " + col);
                Color color = patch.get(col, 1);
                patch.set(col, row, color);
            }
        }
    }
    
    double[][] Laplacian = new double[3][3]; //define kernel
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
        Laplacian[i][j] = -1.0; 
        if (i == 1 && j == 1) Laplacian[i][j] = 8.0;
        }
    }
           
    Picture target = new Picture(picture.width(), picture.height()); //define processed picture
    double sumR = 0;
    double sumG = 0;
    double sumB = 0;
    
    for (int row = 1; row < patch.height() - 1; row++) {                      //Multiplying Kernel
        for (int col = 1; col < patch.width() -1; col ++) {
            
            for (int i = -1; i < 2; i++) {            //within 3X3 kernel X Pixel
                for (int j = -1; j < 2; j++){
                    Color colorS = patch.get(col + j, row + i);
                    int r = colorS.getRed();
                    int g = colorS.getGreen();
                    int b = colorS.getBlue();
                    sumR += (r * Laplacian[i + 1][j + 1]); 
                    sumG += (g * Laplacian[i + 1][j + 1]);
                    sumB += (b * Laplacian[i + 1][j + 1]);            
                }
            }
            int R = (int) Math.round(sumR);
            int G = (int) Math.round(sumG);
            int B = (int) Math.round(sumB);
            if (R > 255) R = 255;
            if (G > 255) G = 255;
            if (B > 255) B = 255;
            if (R < 0) R = 0;
            if (G < 0) G = 0;
            if (B < 0) B = 0;
            Color colorT = new Color(R, G, B);
            target.set(col - 1, row - 1, colorT);
            sumR = 0;
            sumG = 0;
            sumB = 0;        
        }
    }
    return target;   
    }
        
        

    //Returns a new picture that applies an emboss filter to the given picture.
    public static Picture emboss(Picture picture) {
        Picture patch = new Picture(picture.width() + 2, picture.height() + 2);
    
        for (int col = 1; col < (patch.width() - 1); col++) {  //center elements copied from original picture
            for (int row = 1; row < (patch.height() - 1); row++) {
                Color color = picture.get((col - 1), (row - 1));
                patch.set(col, row, color);
            }
        }
    
        for(int col = 0; col < patch.width(); col += (patch.width() - 1)) { //left & right patch elements
            for (int row = 1; row < (patch.height() - 1); row++) {
                if (col == 0) {
                    Color color = picture.get((picture.width() - 1), (row - 1));
                    patch.set(col, row, color);
                }
                if (col == (patch.width() - 1)) {
                    Color color = picture.get(0, (row - 1));
                    patch.set(col, row, color);
                }
            }
        }
        //System.out.println("patch.wisth = " + patch.width());
        for (int row = 0; row < patch.height(); row += (patch.height() - 1)) { //up & down 2 patch elements
            for (int col = 0; col < patch.width(); col++) {
                if (row == 0) {
                    Color color = patch.get(col, patch.height() -2);
                    patch.set(col, row, color);
                }
                if (row == (patch.height() - 1)) {
                    //System.out.println("col = " + col);
                    Color color = patch.get(col, 1);
                    patch.set(col, row, color);
                }
            }
        }
    
        double[][] Emboss = new double[3][3]; //define kernel
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i + j == 0) Emboss[i][j] = -2.0; 
                if (i + j == 1) Emboss[i][j] = -1.0;
                if (i + j == 3) Emboss[i][j] = 1.0; 
                if (i + j == 4) Emboss[i][j] = 2.0;
                if ( i == 1 && j == 1) Emboss[i][j] = 1.0;
            }
        }
           
        Picture target = new Picture(picture.width(), picture.height()); //define processed picture
        double sumR = 0;
        double sumG = 0;
        double sumB = 0;
    
        for (int row = 1; row < patch.height() - 1; row++) {                      //Multiplying Kernel
            for (int col = 1; col < patch.width() -1; col ++) {
            
                for (int i = -1; i < 2; i++) {            //within 3X3 kernel X Pixel
                    for (int j = -1; j < 2; j++){
                        Color colorS = patch.get(col + j, row + i);
                        int r = colorS.getRed();
                        int g = colorS.getGreen();
                        int b = colorS.getBlue();
                        sumR += (r * Emboss[i + 1][j + 1]); 
                        sumG += (g * Emboss[i + 1][j + 1]);
                        sumB += (b * Emboss[i + 1][j + 1]);            
                    }
                }
                int R = (int) Math.round(sumR);
                int G = (int) Math.round(sumG);
                int B = (int) Math.round(sumB);
                if (R > 255) R = 255;
                if (G > 255) G = 255;
                if (B > 255) B = 255;
                if (R < 0) R = 0;
                if (G < 0) G = 0;
                if (B < 0) B = 0;
                Color colorT = new Color(R, G, B);
                target.set(col - 1, row - 1, colorT);
                sumR = 0;
                sumG = 0;
                sumB = 0;        
            }
        }
        return target;   
    }

    // Returns a new picture that applies a motion blur filter to the given picture.
    public static Picture motionBlur(Picture picture) {
        Picture patch = new Picture(picture.width() + 8, picture.height() + 8);
    
        for (int col = 4; col < (patch.width() - 4); col++) {  //center elements copied from original picture
            for (int row = 4; row < (patch.height() - 4); row++) {
                Color color = picture.get((col - 4), (row - 4));
                patch.set(col, row, color);
            }
        }
    
        for (int col = 0; col < 4; col++) {                                      //left patch 0 ~ 3
            for (int row = 4; row < (patch.height() - 4); row++) {
                    Color color = patch.get((patch.width() - 8 + col), row);
                    patch.set(col, row, color);
                }            
        }
        
        for(int col = patch.width() - 4; col < patch.width(); col++) {          //right patch w-4 ~ w-1
            for (int row = 4; row < (patch.height() - 4); row++) {
                    Color color = patch.get(4 + (col - patch.width() + 4), row);
                    patch.set(col, row, color);
                }            
        }
        
        
        //System.out.println("patch.wisth = " + patch.width());
        for (int row = 0; row < 4; row++) {                                    //up patch 0 ~ 3 row
            for (int col = 0; col < patch.width(); col++) {               
                    Color color = patch.get(col, patch.height() - 8 + row);
                    patch.set(col, row, color);             
            }
        }
        
        for (int row = patch.height() - 4; row < patch.height(); row++) {       //down patch h-4 ~ h-1                                 //down patch h-4 ~ h-1 row
            for (int col = 0; col < patch.width(); col++) {               
                    Color color = patch.get(col, 4 + (row - patch.height() + 4));
                    patch.set(col, row, color);             
            }
        }
    
        double[][] MotionBlur = new double[9][9]; //define kernel
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if ( i == j) MotionBlur[i][j] = 1.0 / 9.0;
            }
        }
           
        Picture target = new Picture(picture.width(), picture.height()); //define processed picture
        double sumR = 0;
        double sumG = 0;
        double sumB = 0;
    
        for (int row = 4; row < patch.height() - 4; row++) {                      //Multiplying Kernel
            for (int col = 4; col < patch.width() -4; col ++) {
            
                for (int i = -4; i < 5; i++) {            //within 9X9 kernel X Pixel
                    for (int j = -4; j < 5; j++){
                        Color colorS = patch.get(col + j, row + i);
                        int r = colorS.getRed();
                        int g = colorS.getGreen();
                        int b = colorS.getBlue();
                        sumR += (r * MotionBlur[i + 4][j + 4]); 
                        sumG += (g * MotionBlur[i + 4][j + 4]);
                        sumB += (b * MotionBlur[i + 4][j + 4]);            
                    }
                }
                int R = (int) Math.round(sumR);
                int G = (int) Math.round(sumG);
                int B = (int) Math.round(sumB);
                if (R > 255) R = 255;
                if (G > 255) G = 255;
                if (B > 255) B = 255;
                if (R < 0) R = 0;
                if (G < 0) G = 0;
                if (B < 0) B = 0;
                Color colorT = new Color(R, G, B);
                target.set(col - 4, row - 4, colorT);
                sumR = 0;
                sumG = 0;
                sumB = 0;        
            }
        }
        return target;   
    }
        
        
    
    
    // Test client (ungraded).
    public static void main(String[] args) {
        
    Picture pic = new Picture(args[0]);
    pic.show();
    
    Picture gaussianblur = gaussian(pic);
    gaussianblur.show();
    Picture sharpen = sharpen(pic);
    sharpen.show();
    Picture laplacian = laplacian(pic);
    laplacian.show();
    Picture emboss = emboss(pic);
    emboss.show();
    Picture motionBlur = motionBlur(pic);
    motionBlur.show();
    
    }
    
}   