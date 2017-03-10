package purduecom.sam.mind_app;

import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.View;

import java.util.Random;
import java.util.concurrent.ThreadLocalRandom;

public class exercise_Activity extends AppCompatActivity {

    //GLOBAL arrays for storing information

    //Size of these arrays is irrelevant, we get a data read every .05s so this is ~50 seconds of data. probably too much
    int[] realStream = new int[1000];
    char[] rawStream = new char[2001];

    @Override
    //This block of code gets ran whenever this activity is called by a button or whatever
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_exercise_);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        //TODO this will probably crash the app as it is now;
        beginRead(realStream, rawStream);

        //TODO Add support for device and reading in data
    }

    //TODO This function should begin the input stream from the device to the phone
    //TODO for now, feel free to use dummy data for now to get the functions connected
    public static void beginRead(int[] realStream, char[] rawStream) {
        int flag = 0;

        //will be different Read eventually
        rawStream = dummyRead(rawStream);

        //TODO get REAL data from device and fill array every (realStream.length / 20) seconds



        //TODO after data is put in realStream using parseData, interpret it
        flag = interpret(parseData(realStream,rawStream));

        //TODO create multiple text view representing actions we support and set specific one to visible based on flag
        switch (flag) {
            //TODO replace prints with displaying stuff in app
            case 0: //nothing is done
                Log.d("action", "nothing done");
                break;
            case 1:
                Log.d("action", "something done");
                break;
            //ETC
        }
    }


    public static int interpret(int[] realStream) {
        //after interpretation, flag should be set to an int corresponding with action
        int flag=0;
        //TODO interpret data into decisive actions (grip, move finger, etc)

        return flag;
    }

    //converts the raw stream
    public static int[] parseData(int[] realStream, char[] rawStream){
        //
        for (int i = 0; i < rawStream.length; i++) {
            //43 is ascii value for '+' which seperates ints inside raw stream
            if(i%2 == 0 && rawStream[i] != 43) {
                realStream[i/2] = rawStream[i];
            }
        }
        return realStream;
    }

    //Fills raw data with fake data
    public static char[] dummyRead(char[] rawStream) {
        Random rand = null;
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
        return rawStream;
    }

}
