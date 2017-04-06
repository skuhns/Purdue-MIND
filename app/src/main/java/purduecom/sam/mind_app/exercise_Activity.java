package purduecom.sam.mind_app;

import android.content.Context;
import android.support.v7.app.AppCompatActivity;

import android.os.Bundle;

import android.support.v7.widget.Toolbar;
import android.util.Log;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Date;
import java.util.Random;

public class exercise_Activity extends AppCompatActivity {





    //GLOBAL arrays for storing information

    //Size of these arrays is irrelevant, we get a data read every .05s so this is ~50 seconds of data. probably too much
    int[] realStream = new int[1000];
    char[] rawStream = new char[2001];

    public exercise_Activity() throws FileNotFoundException {
    }


    @Override
    //This block of code gets ran whenever this activity is called by a button or whatever
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        String FILENAME = "MIND_DATA";
        String newSession = "New Session: ";
        DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        Date date = new Date();
        //File file = new File(context.getFilesDir(), FILENAME);
        FileOutputStream fos = null;
        try {
            fos = openFileOutput(FILENAME, Context.MODE_APPEND);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        newSession = newSession.concat(dateFormat.format(date) + "\n\n");

        try {
            fos.write(newSession.getBytes());
            fos.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        String message = "";
        try {
            FileInputStream fis = openFileInput(FILENAME);
            int size = fis.available();
            for (int i = 0; i < size; i++) {
                message = message.concat((char)fis.read() + "");
            }
            System.out.println("APP USAGE HISTORY");
            System.out.println(message + "\n");
            fis.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        setContentView(R.layout.activity_exercise_);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);

        setSupportActionBar(toolbar);

        beginRead(realStream, rawStream);

        //TODO Add support for device and reading in data
    }

    //TODO This function should begin the input stream from the device to the phone
    //TODO for now, feel free to use dummy data for now to get the functions connected
    public void beginRead(int[] realStream, char[] rawStream) {
        Log.d("function", "beginRead");
        int flag = 0;

        //will be different Read eventually
        rawStream = dummyRead(rawStream);
        Log.d("raw stream", Arrays.toString(rawStream));

        //TODO get REAL data from device and fill array every (realStream.length / 20) seconds



        //TODO after data is put in realStream using parseData, interpret it
        realStream = parseData(realStream,rawStream);
        flag = interpret(realStream);
        Log.d("realStream", Arrays.toString(realStream));
        Log.d("flag", Integer.toString(flag));

        //TODO create multiple text view representing actions we support and set specific one to visible based on flag
        switch (flag) {
            //TODO replace logs with displaying stuff in app
            case 0: //nothing is done
                Log.d("action", "nothing done");
                break;
            case 1:
                Log.d("action", "2 of same number in a row!");
                break;
            //ETC
        }
    }


    public static int interpret(int[] realStream) {
        Log.d("function","interpret");
        //after interpretation, flag should be set to an int corresponding with action
        int flag=0;

        //look for patterns (ie 2 of same numbers in a row
        //make sure you only pass over array 1 time or the runtime of the app will slow drastically

        for (int i = 0; i < realStream.length-1; i++) {
            if (realStream[i] == realStream[i+1]) {
                flag = 1;
            }
        }
        //TODO interpret data into decisive actions (grip, move finger, etc)

        Log.d("success", "interpret");
        return flag;
    }

    //converts the raw stream
    public static int[] parseData(int[] realStream, char[] rawStream){
        Log.d("function","parseData");
        //
        for (int i = 0; i < rawStream.length-1; i++) {
            //48 is difference between ascii value for basic ints and actual ints 0-9
            if(i%2 == 0 && rawStream[i] != '+') {
                realStream[i/2] = rawStream[i] - 48;
            }
        }
        Log.d("success","parseData");
        return realStream;
    }

    //Fills raw data with fake data
    public static char[] dummyRead(char[] rawStream) {
        Log.d("function","dummyRead");
        Random rand = new Random();
        int temp = 0;
        for(int i = 0; i < rawStream.length; i++){
            if (i % 2 == 0) {
                temp = rand.nextInt(10);
                switch (temp) {
                    case 0: rawStream[i] = '0';
                        break;
                    case 1: rawStream[i] = '1';
                        break;
                    case 2: rawStream[i] = '2';
                        break;
                    case 3: rawStream[i] = '3';
                        break;
                    case 4: rawStream[i] = '4';
                        break;
                    case 5: rawStream[i] = '5';
                        break;
                    case 6: rawStream[i] = '6';
                        break;
                    case 7: rawStream[i] = '7';
                        break;
                    case 8: rawStream[i] = '8';
                        break;
                    case 9: rawStream[i] = '9';
                        break;
                }
            }
            else {
                rawStream[i] = '+';
            }
        }
        Log.d("success", "dummyRead");
        return rawStream;
    }

    public static void display(int flag) {
        //Possible option: create array of strings corresponding with flags, then display string

    }
}
