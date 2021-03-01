import 'package:flutter/material.dart';
import 'package:flutter_app_firebse/screens/sensor_display/airquality.dart';
import 'package:flutter_app_firebse/screens/sensor_display/amruth.dart';
import 'package:flutter_app_firebse/screens/sensor_display/ravi.dart';
import 'package:flutter_app_firebse/screens/sensor_display/vineesh.dart';
import 'package:flutter_app_firebse/services/auth.dart';
import 'package:firebase_database/firebase_database.dart';
class Home extends StatelessWidget {
  final AuthService _auth = AuthService();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Welcome to weather station"),
        actions: <Widget>[
          FlatButton.icon(
              onPressed: () async {
                  await _auth.signOut();
                },
              icon: Icon(Icons.person),
              label:Text("Sign out")),
        ],
      ),
      body: Container(
        // decoration: BoxDecoration(
        //   image: DecorationImage(
        //     image: AssetImage("images/back.jpg"),
        //     fit: BoxFit.cover,
        //   ),
        // ),
        padding: EdgeInsets.fromLTRB(169.0, 50.0, 50.0, 50.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: <Widget>[
            RaisedButton(
              child: Text('KVV'),
              onPressed: () {
                Navigator.of(context).push(MaterialPageRoute(
                  builder: (context)=>KVV()
                ));
              },
            ),
            RaisedButton(
              child: Text('Amruth'),
              onPressed: () {
                Navigator.of(context).push(MaterialPageRoute(
                    builder: (context)=>Amruth()
                ));
              },
            ),
            RaisedButton(
              child: Text('Ravi'),
              onPressed: () {
                Navigator.of(context).push(MaterialPageRoute(
                    builder: (context)=>Ravi()
                ));
              },
            ),
            RaisedButton(
              child: Text('Vineesh'),
              onPressed: () {
                Navigator.of(context).push(MaterialPageRoute(
                    builder: (context)=>Vineesh()
                ));
              },
            ),
          ],
        ),
      )
    );
  }
}
