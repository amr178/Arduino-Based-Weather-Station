import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_database/ui/firebase_animated_list.dart';
import 'package:flutter/material.dart';
import 'package:firebase_database/firebase_database.dart';
class KVV extends StatelessWidget {
  final Query _ref=FirebaseDatabase.instance.reference().child("KVV");
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Weather at KVV's"),
      ),
      body: Container(
        decoration: BoxDecoration(
          image: DecorationImage(
            image: AssetImage("images/kvv_background.jpg"),
            fit: BoxFit.cover,
          ),
        ),
          child: FirebaseAnimatedList(query: _ref,itemBuilder:(BuildContext context,
            DataSnapshot snapshot,Animation<double>animation,int index){
          print(snapshot.value);
          return Center(
            child: Container(
              padding: EdgeInsets.fromLTRB(2.0, 100.0, 2.0, 2.0),
              child: Text(
                snapshot.value.toString(),
                textAlign: TextAlign.center,
                style: TextStyle(
                    fontSize: 30.0,
                    fontWeight: FontWeight.bold,
                    letterSpacing: 2.0,
                    color: Colors.white,
                ),
              ),
            ),
          );
        } ,),
      ),
    );
  }
}
