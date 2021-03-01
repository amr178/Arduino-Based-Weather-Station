import 'package:flutter/material.dart';
import 'package:flutter_app_firebse/models/user.dart';
import 'package:flutter_app_firebse/screens/authenticate/authenticate.dart';
import 'package:flutter_app_firebse/screens/home/home.dart';
import 'package:provider/provider.dart';
class Wrapper extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    final user = Provider.of<User>(context);
    if(user==null){
      return Authenticate();
    }
    else{
      return Home();
    }
  }
}
