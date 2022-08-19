import { Component, OnDestroy, OnInit } from '@angular/core';
import { Subscription } from 'rxjs';
import { MusicDataService } from '../music-data.service';

@Component({
  selector: 'app-new-releases',
  templateUrl: './new-releases.component.html',
  styleUrls: ['./new-releases.component.css']
})
export class NewReleasesComponent implements OnInit, OnDestroy {

  releases: Array<any>  = [];
  dataSub: Subscription | undefined;

  constructor(private musicDataService: MusicDataService) { }

  ngOnInit(): void {
    
    this.dataSub = this.musicDataService.getNewReleases().subscribe((dt) => {
      this.releases = dt.albums.items;
    });
  }

  ngOnDestroy(): void {
    this.dataSub?.unsubscribe();
  }
}
